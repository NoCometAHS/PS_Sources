#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, m;
    cin >> n >> m;

    TwoVector<LL> dp(n, vector<LL>(1 << 4, 0));
    auto isValid = [](LL status) {

        LL t = 0;
        for (int i = 0; i < 4; i++) {
            if ((status >> i) & 1) {
                if (t % 2) return false;
            }
            else t++;
        }


        return t % 2 == 0;
    };


    for (int i = 0; i < (1 << 4); i++) {
        dp[0][i] = isValid(i);
    }


    for (int i = 1; i < n; i++) {
        for (int pre = 0; pre < (1 << 4); pre++) {
            for (int cur = 0; cur < (1 << 4); cur++) {
                if (pre & cur) continue;
                if (!isValid(pre | cur)) continue;

                dp[i][cur] = (dp[i][cur]+dp[i-1][pre]) % m;
            }
        }
    }

    cout << dp[n-1][0];

    return 0;
}