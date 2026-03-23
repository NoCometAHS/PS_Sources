#include "bits/stdc++.h"

using namespace std;
using LL = long long;

constexpr LL mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<vector<LL>> dp(2, vector<LL>(n+1, 0));
    dp[0][0] = 1;
    dp[1][0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[0][i] = (dp[0][i-1] * 24 + dp[1][i-1] * 2) % mod;
        dp[1][i] = (dp[1][i-1] * 24 + dp[0][i-1] * 2) % mod;
    }

    cout << dp[0][n];

    return 0;
}

/*
~~dp[s가 홀짝 c가 홀짝][문자열 길이]~~

dp[s,c의 합이 짝수][문자열 길이]

*/
