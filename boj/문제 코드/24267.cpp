#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    cin >> n;

    LL ans = 0;

    for (int i = 1; i <= n-2; i++) {
        ans += 1LL*(n - i - 1) * (n - i) / 2;
    }

    cout << ans << '\n';
    cout << 3;
    
    return 0;
}
