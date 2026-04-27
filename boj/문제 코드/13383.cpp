#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int dfs(int cur, TwoVector<int>& graph, vector<bool>& chk) {
    int res = 1;

    chk[cur] = true;
    for (auto& next : graph[cur]) {
        if (chk[next]) continue;

        res += dfs(next, graph, chk);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int> degree(n);

        TwoVector<int> graph(n);
        int e;
        cin >> e;

        while (e--){
            int x, y, z;
            cin >> x >> y >> z;

            graph[x].push_back(y);
            graph[y].push_back(x);

            degree[x] += z;
            degree[y] += z;
        }

        int odd = 0;
        for (auto& i : degree) odd += i % 2;

        vector<bool> chk(n, false);
        bool connected = true;
        int f = 1; 
        for (int i = 0; i < n; i++) {
            int t = dfs(i, graph, chk);

            if (f == 1) f = t;
            else {
                connected &= t == 1;
            }
        }

        if (connected && (odd == 0 || odd == 2)) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}

// 어디 집에서 집까지 간선의 개수가 주어짐.
// 이거 혼자서 만들 수 있는 거냐?
/*
모든 간선을 다 지날수만 있으면 됨. 오일러 경로
*/
