#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    TwoVector<bool> dp(32, vector<bool>(32, false));

    for (int i = 1; i < 32; i++) {
        for (int k = 2; k < 32; k++) {
            bool flag = true;

            for (int p = max(0,k - i); p < k; p++) flag &= dp[i][p];

            dp[i][k] = !flag;
        }
    }

    int n;
    cin >> n;


    for (int i = 1; i <= n; i++) {
        if (dp[i][31]) continue;

        cout << i << '\n';
    }
    return 0;
}
