#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

constexpr int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int f0 = 0, f1 = 1;
    for (int i = 0; i < n; i++) {
        int t = f1;
        f1 = (f0 + f1) % mod;
        f0 = t;
    }

    cout << f0;

    return 0;
}
