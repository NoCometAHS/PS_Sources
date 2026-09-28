#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

constexpr LL nodeMx = 100100;

class SegmentTree{
    vector<LL> segTree;

public:
    SegmentTree() : segTree(nodeMx * 4) {}

    void update(int idx, int v, int node, int fr, int en) {
        if (fr == en) {
            segTree[node] = v;
            return;
        }

        int m = (fr + en) / 2;
        if (idx <= m) update(idx, v, node * 2, fr, m);
        else update(idx, v, node * 2 + 1, m+1, en);

        segTree[node] = max(segTree[node*2], segTree[node*2+1]);
    }

    LL query(int lt, int rt, int node, int fr, int en) {
        if (rt < fr or en < lt) return -1;
        if (lt <= fr and en <= rt) return segTree[node];

        int m = (fr + en) / 2;
        return max(query(lt, rt, node*2, fr, m), query(lt, rt, node*2+1, m+1, en));
    }
};


vector<LL> depth(nodeMx, 0), par(nodeMx, 0), sz(nodeMx, 0);
vector<LL> top(nodeMx, 0), in(nodeMx, 0);

SegmentTree segtree;
vector<vector<iipair>> graph(nodeMx);

vector<LL> edgeValue(nodeMx, 0);


void preHLD(int cur, int p) {
    if (graph[cur].size() > 1 and graph[cur][0].first == p) swap(graph[cur][0], graph[cur][1]);

    for (auto& node : graph[cur]) {
        auto& [nx, w] = node;

        if (nx == p) continue;

        edgeValue[nx] = w;
        depth[nx] = depth[cur] + 1;
        par[nx] = cur;

        preHLD(nx, cur);

        sz[cur] += sz[nx];
        if (sz[graph[cur][0].first] < sz[nx]) swap(graph[cur][0], node);
    }

    sz[cur]++;

    return;
}


void HLD(int cur, int p) {
    static int cnt = 0;
    in[cur] = ++cnt;
    segtree.update(in[cur], edgeValue[cur], 1, 0, nodeMx);

    for (auto& node : graph[cur]) {
        auto& [nx, w] = node;

        if (nx == p) continue;

        top[nx] = (nx == graph[cur][0].first ? top[cur] : nx);

        HLD(nx, cur);
    }
}


LL query(int u, int v) {
    LL ret = 0;
    for (; top[u] ^ top[v]; u = par[top[u]]) {
        if (depth[top[u]] < depth[top[v]]) swap(u, v);

        ret = max(ret, segtree.query(in[top[u]], in[u], 1, 0, nodeMx));
    }

    if (in[u] < in[v]) swap(u, v);
    
    ret = max(ret, segtree.query(in[v]+1, in[u], 1, 0, nodeMx));

    return ret;
}

void update(int idx, int v) {
    segtree.update(in[idx], v, 1, 0 , nodeMx);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;


    
    vector<iipair> edges(n);

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges[i] = iipair(u, v);
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    top[1] = 1;
    preHLD(1, -1);
    HLD(1, -1);

    int q;
    cin >> q;

    while (q--) {
        int qry, a, b;
        cin >> qry >> a >> b;

        if (qry == 1) {
            auto [u, v] = edges[a];
            int child = (par[u] == v ? u : v);

            update(child, b);
        }
        else{
            cout << query(a, b) << '\n';
        }

    }


    return 0;
}