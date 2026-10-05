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

    void update(int idx,  int node, int fr, int en) {
        if (fr == en) {
            segTree[node] = !segTree[node];
            return;
        }

        int m = (fr + en) / 2;
        if (idx <= m) update(idx, node * 2, fr, m);
        else update(idx, node * 2 + 1, m+1, en);

        segTree[node] = segTree[node*2] + segTree[node*2+1];
    }

    LL query(int lt, int rt, int node, int fr, int en) {
        if (rt < fr or en < lt) return 0;
        if (lt <= fr and en <= rt) return segTree[node];

        int m = (fr + en) / 2;
        return query(lt, rt, node*2, fr, m) + query(lt, rt, node*2+1, m+1, en);
    }

    LL bsearch(int lt, int rt) {
        if (query(lt, rt, 1, 0, nodeMx) == 0) return 1e9;

        while (lt < rt) {
            int m = (lt + rt) / 2;

            if (query(lt, m, 1, 0, nodeMx) > 0) {
                rt = m;
            } 
            else {
                lt = m + 1;
            }

        }

        return lt;
    }
};


vector<LL> depth(nodeMx, 0), par(nodeMx, 0), sz(nodeMx, 0);
vector<LL> top(nodeMx, 0), in(nodeMx, 0), inRev(nodeMx, 0);

SegmentTree segtree;
vector<vector<LL>> graph(nodeMx);



void preHLD(int cur, int p) {
    if (graph[cur].size() > 1 and graph[cur][0] == p) swap(graph[cur][0], graph[cur][1]);

    for (auto& nx : graph[cur]) {
        if (nx == p) continue;

        depth[nx] = depth[cur] + 1;
        par[nx] = cur;

        preHLD(nx, cur);

        sz[cur] += sz[nx];
        if (sz[graph[cur][0]] < sz[nx]) swap(graph[cur][0], nx);
    }

    sz[cur]++;

    return;
}


void HLD(int cur, int p) {
    static int cnt = 0;
    in[cur] = ++cnt;
    inRev[cnt] = cur;

    for (auto& nx : graph[cur]) {
        if (nx == p) continue;

        top[nx] = (nx == graph[cur][0] ? top[cur] : nx);

        HLD(nx, cur);
    }
}


LL query(int u, int v = 1) {
    LL ret = 1e9;
    for (; top[u] ^ top[v]; u = par[top[u]]) {
        if (depth[top[u]] < depth[top[v]]) swap(u, v);

        ret = min(segtree.bsearch(in[top[u]], in[u]),  ret);
    }

    if (in[u] < in[v]) swap(u, v);
    
    ret = min(ret,  segtree.bsearch(in[v], in[u]));

    return ret;
}

void update(int idx) {
    segtree.update(in[idx], 1, 0, nodeMx);
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

    top[1] = 1;
    preHLD(1, -1);
    HLD(1, -1);

    int q;
    cin >> q;

    while (q--) {
        int qry, a;
        cin >> qry >> a;

        if (qry == 1) {
            update(a);
        }
        else {
            LL t = query(a);
            cout << (t == 1e9 ? -1 : inRev[t] ) << '\n';
        }

    }


    return 0;
}