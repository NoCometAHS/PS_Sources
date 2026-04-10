#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<vector<LL>> dp(n+1, vector<LL>(10));

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            for (int k = 1; k < 10; k++) {
                for (int p = 1; p <= i; p++) {
                    dp[i][k] += dp[p][k-1];
                }
            }
        }

        LL ans = 0;
        for (int i = 0; i < 10; i++) {
            ans += dp[n][i];
        }

        cout << ans << '\n'; 
    }
    return 0;
}

/*
dp[i번째 자리수인데][k까지의 수를 썼을 때] 경우의 수
*/