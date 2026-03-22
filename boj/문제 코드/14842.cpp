#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double w, h, n;
    cin >> w >> h >> n;

    double s1 = h/w, s2 = - h/w, d2 = h;
    
    double x = w/n;
    double ans = 0;

    for (int i = 0; i < n - 1; i++) {
        ans += abs(s1*x - (s2*x + d2));

        x += w/n;
    }

    cout << fixed;
    cout.precision(7);
    
    cout << ans;
    return 0;
}
