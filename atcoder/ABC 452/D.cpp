#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s, t;
    cin >> s >> t;


    vector<LL> dp(t.length(), -1);
    LL ans = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int k = t.length()-1; k >= 0; k--) {
            if (s[i] == t[k]) {
                dp[k] = max(dp[k], (k == 0 ? i : dp[k-1]));
            }
        }

        ans += i - dp.back();
    }

    cout << ans;

    return 0;
}

/**/