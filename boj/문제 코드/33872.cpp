#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int dfs(int cur, int res, vector<int>& arrivals, TwoVector<int>& graph, vector<int>& banana, int end, int h) {
    if (!arrivals[cur]) res += banana[cur];

    if (!h) {
        if (cur == end)
            return res;

        return -1;
    }

    arrivals[cur]++;

    int ret = -1;
    for (auto& next : graph[cur]) {
        if (arrivals[next] >= 2) continue;

        ret = max(dfs(next, res, arrivals, graph, banana, end, h-1), ret);
    }

    arrivals[cur]--;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, h, start, end;
    cin >> n >> h >> start >> end;
    start--, end--;

    vector<int> banana(n);
    for (auto& i : banana) cin >> i;

    vector<int> danger(n);
    for (auto& i : danger) cin >> i;

    TwoVector<int> graph(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        if (danger[a] || danger[b]) continue;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> arrivals(n, 0);
    cout << dfs(start, 0, arrivals, graph, banana, end, h);

    return 0;
}

/*
트리
각 2번 방문 가능
목적지 경우 가능
h가 0일때 목적지여야만 함.

도달하지 못하는 곳이 있음.
-> 트리 잘라버려.

n이 엄청 작단 말이지.
 
벨만 포드로 dp?
그냥 dfs돌려도 되는 거 아닌가

*/