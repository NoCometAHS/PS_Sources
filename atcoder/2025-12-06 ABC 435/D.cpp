#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

void dfs(int cur, vector<bool>& color, TwoVector<int>& graph) {
    color[cur] = true;

    for (auto& next : graph[cur]) {
        if (color[next]) continue;

        dfs(next, color, graph);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    TwoVector<int> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[v].push_back(u);
    }

    vector<bool> color(n, false);

    int qCnt;
    cin >> qCnt;

    while (qCnt--) {
        int q, node;
        cin >> q >> node;

        node--;

        if (q == 1) {
            if (!color[node]) dfs(node, color, graph);
        }
        else {
            cout << (color[node] ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}

/*
역그래프 가지고 있고
색칠 할 때, 연결된 곳 다 들러서 색칠해버리면 검사할 때 이동 안 해도됨
색칠은 결국 O(n)이고

*/