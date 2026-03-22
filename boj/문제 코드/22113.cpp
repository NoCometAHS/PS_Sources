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

    vector<int> bus(m);
    for (auto& i : bus) cin >> i;

    TwoVector<int> cost(n, vector<int>(n));
    for (auto& v : cost) for (auto& i : v) cin >> i;

    int ans = 0;
    int cur = bus[0];
    for (int next = 1; next < m; next++) {
        ans += cost[cur-1][bus[next]-1];
        cur = bus[next];
    }

    cout << ans;
    return 0;
}
