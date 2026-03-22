#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<iipair> arr(n);
    for (auto& [a, b] : arr) cin >>a >> b;

    int ans = 0;
    for (auto& [a, b] : arr) {
        if (ans % (a+b) < b) ans += b - ans % (a + b);

        ans += 1;
    }

    cout << ans;
    return 0;
}
