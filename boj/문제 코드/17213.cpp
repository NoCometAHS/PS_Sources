#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    TwoVector<int> dp(n+1, vector<int>(m+1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = i; k <= m; k++) {
            for (int p = i-1; p <= k - 1; p++) {
                dp[i][k] += dp[i-1][p];
            }
        }
    }

    cout << dp[n][m];
    return 0;
}

/*
n개의 자연수로 m의 합을 만들 수 있는 경우의 수잖아!

dp?

dp[n] : n개로 m을 만들수 있는 경우의 수
dp[n][m] += dp[n-1][n-1 ~ m-1]
*/
