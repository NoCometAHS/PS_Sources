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
        LL x;
        cin >> x;
 
 
        LL ans = 1e18;
        for (int i = 0; i < 63; i++) {
            for (int k = 0; k < 62; k++) {
                ans = min(ans, abs((1LL << i) + (1LL << k) - x));
            }
        }
 
        cout << ans << '\n';
    }


    return 0;
}