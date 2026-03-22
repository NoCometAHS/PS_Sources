#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> arr(6);
    for (auto& i : arr) cin >> i;

    int r, g, b;
    cin >> r >> g >> b;


    double v, s, h, m = min({r, g, b});
    v = max({r, g, b});
    s = 255 * (v - m)/v;

    if (v == r) {
        h = 60*(g - b) / (v - m);
    }
    else if (v == g) {
        h = 120 + 60*(b-r)/(v - m);
    }
    else {
        h = 240 + 60*(r-g)/(v - m);
    }

    if (h < 0) h += 360;

    if (arr[0] <= h && h <= arr[1] && arr[2] <= s && s <= arr[3] && arr[4] <= v && v <= arr[5]) {
        cout << "Lumi will like it.";
    }
    else {
        cout << "Lumi will not like it.";   
    }


    return 0;
}
