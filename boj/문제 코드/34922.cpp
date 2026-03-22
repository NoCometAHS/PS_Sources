#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double w, h, r;
    cin >> w >> h >> r;

    
    cout << fixed;
    cout.precision(3);

    cout << w * h - r * r * 3.141592 / 4;
    return 0;
}
