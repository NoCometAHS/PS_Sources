#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

vector<vector<LL>> primeDivisor(220200);

void sieve() {
    for (int i = 2; i < 220200; i++) {
        if (!primeDivisor[i].empty()) continue;

        primeDivisor[i].push_back(i);

        for (int k = i+i; k < 220200; k+=i) {
            primeDivisor[k].push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve();

    LL tc;
    cin >> tc;

    while (tc--) {
        LL n, k;
        cin >> n >> k;

        vector<LL> dp(n+1, 0);
        
        for (int i = k+1; i <= n; i++) {
            dp[i] = 1e9;
            for (auto& p : primeDivisor[i]) {
                dp[i] = min(dp[i], p*dp[i/p]);
            }

            dp[i] += 1;
        }

        LL ans = 0;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;

            ans += dp[t];
        }

        cout << ans << '\n';
    }
    return 0;
}