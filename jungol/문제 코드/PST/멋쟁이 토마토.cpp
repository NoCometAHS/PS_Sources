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

    vector<Node> segTree;  

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
        if (lt <= fr and en <= rt) {
            return segTree[cn].v - segTree[pn].v;
        }

        int m = (fr + en) / 2;
        return query(lt, rt, segTree[pn].lt, segTree[cn].lt, fr ,m) + query(lt, rt, segTree[pn].rt, segTree[cn].rt, m+1 ,en);
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;

    vector<LL> sortedArr(arr), compressedArr;
    sort(sortedArr.begin(), sortedArr.end());

    for (const auto& i : arr) {
        compressedArr.push_back(lower_bound(sortedArr.begin(), sortedArr.end(), i) - sortedArr.begin());
    }

    pSegTree pst;
    pst.init(0, 0, 100100);

    for (int i = 0; i < n; i++) {        
        pst.update(compressedArr[i], 1, i, i+1, 0, 100100);
    }

    while (m--) {
        int s, e, l ,h;
        cin >> s >> e >> l >> h;

        l = lower_bound(sortedArr.begin(), sortedArr.end(), l) - sortedArr.begin();
        h = upper_bound(sortedArr.begin(), sortedArr.end(), h) - sortedArr.begin() - 1;


        cout << pst.query(l, h, s - 1, e, 0, 100100) << '\n';
    }


    return 0;
}


/*
좌표 압축 먼저 해야 할 듯.
값을 인덱스로 하는 세그 트리에 대해서 pst하면 되는 건가.

*/