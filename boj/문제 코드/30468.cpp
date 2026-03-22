#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, s, d, i ,l;
    cin >> s >> d >> i >> l >> n;

    int ans = n*4 - (s + d + i + l);

    if (ans <= 0) cout << 0;
    else cout << ans;

    return 0;
}
