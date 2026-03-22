#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;
    sort(arr.begin(), arr.end());

    int t;
    cin >> t;

    vector<LL> ans;
    priority_queue<iipair, vector<iipair>, greater<iipair>> pq;
    for (auto& i : arr) pq.emplace(0, i);

    arr.insert(arr.begin(), 0);
    for (int i = 0; i < n; i++) {
        for (int k = 0, num = arr[i]+1; k < 1000 && num < arr[i+1]; k++, num++) {
            LL l = num - arr[i] - 1, r = arr[i+1] - num - 1;
            pq.emplace(l * r + l + r, num);
            //cout << l * r + l + r << ' ' << num << '\n';
        }

    }

    for (int i = n; i > 0; i--) {
        for (int k = 0, num = arr[i]-1; k < 1000 && num > arr[i-1]+1000; k++, num--) {
            LL l = num - arr[i-1] - 1, r = arr[i] - num - 1;
            pq.emplace(l * r + l + r, num);
        // cout << l * r + l + r << ' ' << num << '\n';
        }

    }
    // 마지막 왼족 수 안 넣음.

    while (!pq.empty() && ans.size() < t) {
        auto [cnt, num] = pq.top();
        pq.pop();

        ans.push_back(num);
    }


    while (ans.size() < t) {
        ans.push_back(++arr.back());
    }

    for (auto& i : ans) {
        cout << i << " ";
    }

    return 0;
}

/*

정수 집합 S에 있는 수가 
포함 안 되는 구간이면 *좋은 구간*


좋은 구간에 *포함이 적게 된 수*면 좋은 수.
같거나, 무한개에 포함되는 수끼리는 *작은 수*가 좋은 수

----
일단 집합 안에 있는 수들이 가장 작음.

집합을 수직 선 상에 표기한다면

    집합 구간에 포함 안 되는 왼쪽
    - 유한한 구간 개수를 가짐, 집합에 0이 포함 되어 있다고 생각한다면 아래와 똑같은 조건임.
    집합 구간에 포함 되는 안쪽
    - 유한한 구간 개수를 가짐
 
    유한한 구간 개수를 가질 때,
    - 자신을 포함한 최장 구간이 있을 때, 왼쪽 수 개수, 오른쪽 수 개수의 곱이 가장 작은게 좋은 수네.
    - 끝점에 가까울 수록 구간에 적게 포함 된

    집합 구간에 포함 안 되는 오른쪽
    - 얘네는 다 무한이니, 가장 안 좋은 수이자, 출력해야 한다면 작은 순서대로.


1단 집합안에 있는 수를 다 넣어.
pq에 패어로 구간에 포함된 개수, 그 수를 넣을가야.
근데, 끝점에 가까운 얘들만 넣고 계속 그렇게 넣어가자.

마지막까지 부족하면, 맨 왼쪽에 있는 놈들 차례로.
*/