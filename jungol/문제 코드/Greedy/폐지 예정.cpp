#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int init(int cur, int p, int lv, vector<int>& endTime,  vector<iipair>& order,  const TwoVector<int>& graph) {
    int res = 1e9;

    for (const auto& next : graph[cur]) {
        if (next == p) continue;

        res = min(res , init(next, cur, lv+1, endTime, order, graph));
    }
    
    endTime[cur] = min(endTime[cur], res);
    order.emplace_back(endTime[cur], cur);

    return endTime[cur];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n) {

        TwoVector<int> graph(n+1);
        vector<int> endTime(n+1, 0);
        vector<iipair> order;
        for (int i = 2; i <= n; i++) {
            int u, t;
            cin >> u >> t;

            endTime[i] = t;
            graph[i].push_back(u);
            graph[u].push_back(i);
        }


        init(1, -1, 0, endTime, order, graph);
        sort(order.begin(), order.end());

        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (order[i].first+1 < i) {
                ans = false;
                break;
            }
        }


        if (ans) {
            cout << "yes\n";
            for (int i = 1; i < n; i++) cout << order[i].second << ' ';
            cout << '\n';
        }
        else {
            cout << "no\n";
        }



        cin >> n;
    }
    return 0;
}