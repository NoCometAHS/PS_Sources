#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    int mx = -1e9, mn = 1e9;

    while (n--) {
        int x, y;
        cin >> x >> y;

        mx = max(mx, y);
        mn = min(mn, y);
    }

    cout << mx - mn;

    return 0;
}