#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int l, r, a;
    cin >> l >> r >> a;

    int leftA;
    if (l < r) {
        leftA = max(0, a - (r - l));
        l += a - leftA;
    }
    else {
        leftA = max(0, a - (l - r));
        r += a - leftA;
    }

    l = min(l, r);

    cout << l*2 + leftA - leftA % 2;

    return 0;
}
