#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

vector<int> graph[5050];
vector<iipair> range(5050, {0, 0});
vector<int> sz(5050, 0);

ll dfs(int cur, int par = -1) {

    ll ret = 0;
    vector<iipair> child;
    sz[cur] += 1;

    for (auto& next : graph[cur]) {
        if (next == par) continue;

        ll res = dfs(next, cur);
        sz[cur] += sz[next];

        ret += res;
        child.emplace_back(sz[next], next);
    }

    sort(child.begin(), child.end());

    for (auto& [len, next] : child) {
        ll& curMinLength = (range[cur].first <= range[cur].second ? range[cur].first : range[cur].second);
        ll& nextMinLength = (range[next].first <= range[next].second ? range[next].first : range[next].second);

        ret += curMinLength + nextMinLength + 1;
        curMinLength += range[next].first + range[next].second + 1;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << dfs(1);


    return 0;
}