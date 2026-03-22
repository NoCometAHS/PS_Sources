#include "bits/stdc++.h"

using namespace std;
using LL = long long;

int main() {
    LL n, m, t, s;
    cin >> n >> m >> t >> s;

    LL home = n + (n-1)/8 * s, dok = t + m + (m-1)/8 * s  + (m-1) / 8 * t * 2;

    if (home < dok) {
        cout << "Zip\n" << home;
    }
    else {
        cout << "Dok\n" << dok;
    }


    return 0;
}