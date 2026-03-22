#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    int ans = 0;

    ans += n*10;
    if (n >= 3) ans += 20;
    if (n == 5) ans += 50;
    if (m > 1000) ans = max(0, ans - 15);
    cout << ans;
    return 0;
}
