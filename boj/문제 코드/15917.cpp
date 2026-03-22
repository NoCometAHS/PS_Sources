#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        cout << (__builtin_popcount(n) == 1) << '\n';
    }
    return 0;
}
