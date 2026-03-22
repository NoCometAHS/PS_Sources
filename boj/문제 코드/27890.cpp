#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x, n;
    cin >> x >> n;

    for (int i = 0; i < n; i++) {
        if (x % 2) {
            x = (2 * x) ^ 6;
        }
        else {
            x = (x/2) ^ 6;
        }
    }

    cout << x;

    return 0;
}
