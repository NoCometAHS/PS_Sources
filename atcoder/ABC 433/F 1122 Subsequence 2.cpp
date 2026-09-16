#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

constexpr int mod = 998244353;

LL fact(LL n) {
    LL ret = 1;
    for (int i = 1; i <= n; i++) ret *= i;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;

    vector<vector<int>> pos(10);
    for (int i = 0; i < str.length(); i++) {
        pos[str[i] - '0'].push_back(i);
    }

    int ans = 0;
    for (int num = 0; num < 9; num++) {
        for (int i = 0; i < pos[num].size(); i++) {
            int NexNumCnt = pos[num+1].end() - upper_bound(pos[num+1].begin(), pos[num+1].end(), pos[num][i]);

            ans += 
            ans %= mod;
        }
    }

    cout << ans;

    return 0;
}

// c랑 똑같은데, 연속하지 않아도 되는 부분 문자열 고르기.
/*

각 수마다 주의 깊게 봐야 하는 수는 1개로 정해져 있음. 오른쪽을 향해서만 볼 때.

0은 1을 봐야하고,
1은 2,
...
8은 9

자신이 몇 번째 등장했는 지를 알고, 오른쪽에 특정 수가 몇개 있는 지 O(n)보다 빠르게 안다면, |S|*10 정도로 끝낼 수 있지 않을까.

배열에 수를 인덱스로 수열의 위치를 값으로 넣어두고 이진 탐색하면 몇개 있는 지 쉽게 알 수 있어.

다 알았을 때, 경우의 수가 몇개인지 구하는 수식이 뭐지.

n개 고르는 경우, 
(지금수-1 *....) * (다음수 개수 * 다음수 개수 -1 ..)

다 더해야 하는데?

시 간 이...
*/