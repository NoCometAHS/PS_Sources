#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<LL> dp(1010, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < 1010; i++) {
        dp[i] = 1;
        for (int k = 1;  i - k - k > 0; k++) {
            dp[i] += dp[k];
        }
        if (i % 2 == 0) dp[i] += dp[i/2];

    }

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }
    return 0;
}

/*
왼쪽 오른쪽 동시에 볼 필요 없어.
처음 뻗어 나갈 때만, 양쪽으로 뻗어 나갈 수 있는 지만 보면, 나머진 그냥 진짜 그냥 펼치면 되는 거 아닌가?

펼쳐지는 수조차 팰린드롬이어야 한다.

그렇다면
dp[수가 i일때] 팰린드롬 개수
*/