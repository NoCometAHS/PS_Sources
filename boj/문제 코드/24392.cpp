#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

constexpr LL mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    TwoVector<int> board(n, vector<int>(m));
    for (int i = n-1; i >= 0; i--) {
        for (int k = 0; k < m; k++) {
            cin >> board[i][k];
        }
    }

    TwoVector<int> dp(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        dp[0][i] = board[0][i];
    }

    int dx[] = {-1, 0, 1};

    for (int i = 0; i < n-1; i++) {
        for (int k = 0; k < m; k++) {
            for (int d = 0; d < 3; d++) {
                int nx = k + dx[d], ny = i+1; 
                
                if (nx < 0 || nx >= m || !board[ny][nx]) continue;

                dp[ny][nx] = (dp[ny][nx] + dp[i][k]) % mod;
            }
        }
    }

    LL ans = 0;
    for (auto& i : dp[n-1]) {
        ans = (ans + i) % mod;
    }

    cout << ans;
    return 0; 
}
