#include "bits/stdc++.h"

using namespace std;

int main() {
    int p, m, c, x;
    cin >> p >> m >> c >> x;

    int ans = 1e9;
    for (int i = 1; i <= p; i++) {
        for (int k = 1; k <= m; k++) {
            for (int q = 1; q <= c; q++) {
                ans = min(ans, abs((i + k) * (k + q) - x));
            }
        }
    }

    cout << ans;

    return 0;
}