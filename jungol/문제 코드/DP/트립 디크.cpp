#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

ll dp[53][53][4][53];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, m;
    cin >> n >> m;


    dp[1][0][0][1] = 1;
    dp[0][1][1][1] = 1;
    dp[0][0][2][1] = 1;
    

    for (int w = 2; w <= n; w++) {
        for (int a = 0; a < 52; a++) {
            for (int b = 0; b < 52; b++) {
                for (int last = 0; last < 4; last++) {
                    ll prv = dp[a][b][last][w-1];

                    if (last != 0) dp[a+1][b][0][w] += prv;
                    if (last == 1) dp[a][b+1][3][w] += prv;
                    else if (last != 3) dp[a][b+1][1][w] += prv;
                    if (last != 2) dp[a][b][2][w] += prv;
                }
            }
        }
    }


    ll ans = 0;
    for (int a = 0; a < 52; a++) {
        for (int b = 0; b < 52; b++) {
            int c = n - a - b;
            if (c < 0) continue;

            if (max({a,b,c}) - min({a,b,c}) <= m) {
                ans += dp[a][b][0][n] + dp[a][b][1][n] + dp[a][b][2][n] + dp[a][b][3][n];
            }

            if (n % 2) {
                c = n/2 - a - b + 1;
                if (max({a*2-1, b*2, c*2}) - min({a*2-1, b*2, c*2}) <= m) {
                    ans -= dp[a][b][0][n/2+1];
                }
                if (max({a*2, b*2-1, c*2}) - min({a*2, b*2-1, c*2}) <= m) {
                    ans -= dp[a][b][1][n/2+1];
                }
                if (max({a*2, b*2, c*2-1}) - min({a*2, b*2, c*2-1}) <= m) {
                    ans -= dp[a][b][2][n/2+1];
                }
            }
            else {
                c = n/2 - a - b;
                if (max({a*2, b*2, c*2}) - min({a*2, b*2, c*2}) <= m) {
                    ans -= dp[a][b][1][n/2];
                }
            }

            
        }
    }

    cout << ans;

    return 0;
}