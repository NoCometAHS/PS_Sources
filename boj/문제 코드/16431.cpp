#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    iipair arr[3];
    for (auto& [r, c] : arr) cin >> r >> c;

    int len1 = max(abs(arr[2].first-arr[0].first), abs(arr[2].second - arr[0].second));
    int len2 = abs(arr[2].first-arr[1].first) + abs(arr[2].second - arr[1].second);

    if (len1 < len2) {
        cout << "bessie";
    }
    else if (len1 > len2) {
        cout << "daisy";
    }
    else {
        cout << "tie";
    }

    return 0;
}
