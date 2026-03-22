#include "bits/stdc++.h"

using namespace std;
using iipair = pair<int,int>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<iipair> arr(n);
    for (auto& [a, b] : arr) cin >> a >> b;

    while (m--) {
        int g, x, y;
        cin >> g >> x >> y;

        int ans = 0;
        for (auto& [a, b] : arr) {
            ans += x <= a && y <= b && a+b <= g;
        }

        cout << ans << '\n';

    }
    return 0;
}