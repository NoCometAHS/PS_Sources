#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    TwoVector<iipair> graph(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].emplace_back(1, v);
    }


    for (int i = 1; i <= n; i++) {
        int mn = 1e9, mnIdx, idx = 0;

        for (const auto& [c, next] : graph[i]) {
            if (mn > next) {
                mn = next;
                mnIdx = idx;
            }

            idx++;    
        }
        
        if (mn != 1e9) {
            graph[i][mnIdx].first = 0;
        }
    }


    vector<int> dist(n+1, 1e9);
    priority_queue<iipair, vector<iipair>, greater<iipair>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto& [c, next] : graph[cur]) {
            int nextCost = cost + c;

            if (dist[next] <= nextCost) continue;
            dist[next] = nextCost;
            pq.emplace(nextCost, next);
        }
    }

    cout << (dist[t] == 1e9 ? -1 : dist[t]);

    return 0;
}

