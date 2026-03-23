#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<double> arr(3), r(3);
    for (auto& i : arr) cin >> i;
    for (auto& i : r) cin >> i;

    double mn = 1e9;
    for (int i = 0; i < 3; i++) {
        mn = min(mn, arr[i]/r[i]);
    }

    
    cout << fixed;
    cout.precision(4);
    for (int i = 0; i < 3; i++) {
        cout << arr[i] - r[i] * mn << ' ';
    }

    return 0;
}