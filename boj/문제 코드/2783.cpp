#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double x, y;
    int n;
    cin >> x >> y >> n;

    while (n--) {
        double a, b;
        cin >> a >> b;

        if (1000/b * a < 1000/y * x) {
            x = a;
            y = b;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << 1000/y * x;

    return 0;
}
