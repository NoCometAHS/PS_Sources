#include "bits/stdc++.h"

using namespace std;

using LL = long long;
using iipair = pair<LL,LL>;

class pSegTree{
    struct Node {
        int v;
        int lt, rt;

        Node() : v(0), lt(-1), rt(-1){};
    };

    vector<Node> segTree;   //x축을 그 루트로

public :

    pSegTree() : segTree(100100){}

    void init(int node, int lt, int rt) {
        if (lt == rt) return;

        segTree[node].lt = segTree.size();
        segTree.emplace_back();
        
        segTree[node].rt = segTree.size();
        segTree.emplace_back();

        int m = (lt + rt) / 2;
        init(segTree[node].lt, lt, m);
        init(segTree[node].rt, m+1, rt);
    }

    void update(int idx, int val, int pn, int cn, int lt, int rt) {
        if (lt == rt) {
            segTree[cn].v = segTree[pn].v + val;

            return;
        }

        int m = (lt + rt) / 2;
        if (idx <= m) {
            segTree[cn].lt = segTree.size();
            segTree.emplace_back();

            segTree[cn].rt = segTree[pn].rt;

            update(idx, val, segTree[pn].lt, segTree[cn].lt, lt, m);
        }
        else {
            segTree[cn].rt = segTree.size();
            segTree.emplace_back();

            segTree[cn].lt = segTree[pn].lt;

            update(idx, val, segTree[pn].rt, segTree[cn].rt, m+1, rt); 
        }

        segTree[cn].v = segTree[segTree[cn].lt].v + segTree[segTree[cn].rt].v;
    }


    int query(int lt, int rt, int pn, int cn, int fr, int en) {
        if (rt < fr || en < lt) return 0;
        if (lt <= fr and en <= rt) return segTree[cn].v - segTree[pn].v;

        int m = (fr + en) / 2;

        return query(lt, rt, segTree[pn].lt, segTree[cn].lt, fr ,m) + query(lt, rt, segTree[pn].rt, segTree[cn].rt, m+1 ,en);
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        vector<iipair> arr(n);
        for (auto& [x, y] : arr) cin >> x >> y;
        sort(arr.begin(), arr.end());

        pSegTree pst;
        pst.init(0, 0, 100100);

        for (int i = 0; i < n; i++) {
            pst.update(arr[i].second, 1, i, i+1, 0, 100100);
        }
        
        int ans = 0;
        while (m--) {
            int x1, x2, y1, y2;
            cin >> x1 >> x2 >> y1 >> y2;

            int pn = lower_bound(arr.begin(), arr.end(), iipair{x1, -1e9}) - arr.begin();
            int cn = lower_bound(arr.begin(), arr.end(), iipair{x2, 1e9}) - arr.begin();

            ans += pst.query(y1, y2, pn, cn, 0, 100100);
        }

        cout << ans << '\n';
    }

    return 0;
}