#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n;
    cin >> n;

    vector<iipair> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;

    }

    sort(arr.begin(), arr.end());

    LL sum = arr.back().first;
    LL mx = arr.back().first*3;
    int ansIdx = arr.size()-1;
    for (int i = arr.size()-2; i >= 0; i--) {
        sum += arr[i].first;
        LL cur = sum + arr[i].first + arr.back().first;
        if (cur > mx) {
            mx = cur;
            ansIdx = i;
        }
    }

    cout << n - ansIdx << '\n';
    for (int i = n-1; i >= ansIdx; i--) cout << arr[i].second << ' ';
    return 0;
}

/*
일단 LL
가장 큰 값 하나만 두고 봐보자.
다른 값을 추가해가면서 보면 그냥 얼마나 차이나는 지 알 수 있으니깐 ㄱㅊㄱㅊ한 것 같은데?
*/