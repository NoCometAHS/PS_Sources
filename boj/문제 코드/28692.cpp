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

    LL x = 0, xx = 0, y = 0, xy = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        x += a;
        y += b;
        xx += a*a;
        xy += a*b;
    }

    if (x*x == n*xx) {
        cout <<  "EZPZ";
    }
    else {
        cout << fixed;
        cout.precision(10);
        double a2 = (1.0*n*xy - x*y) / (n*xx - x*x);
        cout << a2 << ' ' << 1.0*(y - a2*x) / n;
    }
    return 0;
}
