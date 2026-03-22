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

        int ans = 0;
        while (n > 1) {
            ans += n % 2;
            n = (n+1)/2;
        }

        cout << ans << '\n';
    }
    return 0;
}
