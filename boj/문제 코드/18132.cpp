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
    
    vector<LL> dp(5500, 0);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 5;

    for (int i = 3; i <= 5000; i++) {
        dp[i] += dp[i-1]*2 % mod;
        dp[i] %= mod;
        
        for (int k = 1; k < i; k++) {
            dp[i] += dp[k - 1] * dp[i - k - 1] % mod;
            dp[i] %= mod;
        }
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
dp로 풀 수 있을 것 같은데,


*/