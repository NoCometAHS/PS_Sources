#include "bits/stdc++.h"

using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        vector<double> a(9);
        for (auto& i : a) cin >> i;

        cout << (int)min(floor(min({a[0]/8, a[1]/8, a[2]/4, a[3], a[4]/9}) * 16), (a[5] + floor(a[6]/30) + floor(a[7] / 25) + floor(a[8] / 10))) << '\n';
    }
    return 0;
}