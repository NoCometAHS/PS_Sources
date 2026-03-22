#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;


    vector<int> arr(n);

    for (auto& i : arr) {
        cin >> i;
    }

    while (m--) {
        int l, h;
        cin >> l >> h;
        l--, h--;

        int mx = -1;
        for (auto& i  : arr) {
            mx = max(mx, i);
        }

        if (arr[h] == mx) continue;

        arr[l]--;
    }

    for (auto& i : arr) cout << i << ' ';

    return 0;
}
