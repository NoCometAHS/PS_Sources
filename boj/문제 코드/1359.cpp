#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, p;
    cin >> n >> m >> p;

    int ans = 0, t = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) != m) continue;

        for (int k = 0; k < (1 << n); k++) {
            if (__builtin_popcount(k) != m) continue;
            t++;
            ans += __builtin_popcount(i & k) >= p;
        }
    }

    cout << fixed;
    cout.precision(9);
    
    cout << 1.0 * ans / t;
    return 0;
}
