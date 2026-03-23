#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int dfs(int cur, int par, vector<int>& dp, vector<vector<int>>& graph) {
    if (dp[cur]) return dp[cur];

    dp[cur] = 1;
    for (auto& c : graph[cur]) {
        if (c == par) continue;

        dp[cur] += dfs(c, cur, dp, graph);
    }

    return dp[cur];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, r, q;
    cin >> n >> r >> q;

    vector<vector<int>> graph(n+1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dp(n+1, 0);
    dfs(r, -1, dp, graph);
    while (q--) {
        int v;
        cin >> v;

        cout << dp[v] << '\n';

    }
    return 0;
}