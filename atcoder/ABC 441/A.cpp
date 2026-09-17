#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int p, q, x, y;
    cin >> p >> q >> x >> y;

    if (p <= x && x <= p + 99 && q <= y && y <= q + 99) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    
    return 0;
}
