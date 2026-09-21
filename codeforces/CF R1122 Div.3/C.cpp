#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        string str;
        cin >> str;

        if (str[0] == '1') {
            int ans = 0;
            for (auto& i : str) ans += i =='0';
            cout << ans << '\n';
            continue;
        }

        vector<vector<LL>> dp(2, vector<LL>(n));
        dp[0][0] = str[0] == '1'; 
        dp[1][0] = str[0] == '0';

        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i-1] + str[i] - '0';
            dp[1][i] = min(dp[0][i-1], dp[1][i-1]) + (str[i] == '0');
        }

        cout << min(dp[0].back(), dp[1].back()) << '\n';
    }
    return 0;
}