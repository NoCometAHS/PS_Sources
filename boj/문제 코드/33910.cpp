#include "bits/stdc++.h"

using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    LL ans = 0;
    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;

    LL mn = 1e9;
    for (int i = n - 1; i >= 0; i--) {
        mn = min(mn, arr[i]);

        ans += mn;
    }

    cout << ans;
    return 0;
}