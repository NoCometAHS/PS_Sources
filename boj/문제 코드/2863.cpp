#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<vector<int>> arr(2, vector<int>(2));
    for (auto& v : arr) {
        for (auto& i : v) cin >> i;
    }

    int ans = 0;
    double v = 0;
    for (int i = 0; i < 4; i++) {
        double t = 1.0 * arr[0][0] / arr[1][0] + 1.0 * arr[0][1] / arr[1][1];

        if (v < t) {
            ans = i;
            v = t;
        }

        t = arr[0][0];
        arr[0][0] = arr[1][0];
        arr[1][0] = arr[1][1];
        arr[1][1] = arr[0][1];
        arr[0][1] = t;
    
    }

    cout << ans;

    return 0;
}