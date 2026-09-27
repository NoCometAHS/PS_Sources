#include "bits/stdc++.h"

using namespace std;

using LL = long long;
using iipair = pair<LL,LL>;

constexpr int nodeMX = 200200;

class pSegTree{
    struct Node {
        int v;
        int lt, rt;

        Node() : v(0), lt(-1), rt(-1){};
    };

    vector<Node> segTree; 

public :

    pSegTree() : segTree(nodeMX){}

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


    int query(int curVal, int pn, int cn, int fr, int en) {
        if (fr == en) {
            return fr;
        }

        int m = (fr + en) / 2;

        LL leftNodeVal =  segTree[segTree[cn].lt].v - segTree[segTree[pn].lt].v;
        LL rightNodeVal =  segTree[segTree[cn].rt].v - segTree[segTree[pn].rt].v;

        if (m+1 <= rightNodeVal + curVal) {
            return query(curVal, segTree[pn].rt, segTree[cn].rt, m+1, en);
        }
        else {
            return query(curVal + rightNodeVal, segTree[pn].lt, segTree[cn].lt, fr, m);
        }
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    pSegTree pst;
    pst.init(0, 0, nodeMX);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        pst.update(t, 1, i, i+1, 0, nodeMX);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << pst.query(0, l-1, r, 0, nodeMX) << '\n';
    }
    
    return 0;
}

/*
h개의 논문의 cite가 h개 이상인 최대의 h를 구하라.

왼쪽 노드와 오른쪽 노드의 h개 같다면, 같다고 해도 바뀔 수 있어.
3 3 3 5 5 5 |  3 3 3 5 5
라고 한다면 h는 5가 될거야.

전체에 대해서 찾는 법은?
index sort 후 O(n)에 찾기. -> TLE 더 빨리 찾아야 함.

이진탐색 세그 트리 같은 느낌으로 안 되나?
오른쪽과 왼쪽의 개수를 비교해.
오른쪽이 가능하면 무조건 오른쪽으로. (index <= cnt)
애매 하네. *이거로?*

자기 보다 큰 얘들 다 더했을 때, index보다 크면 된다.

뭔가 단조성? 딱 끊기는 부분이 존재해서 이분 탐색 같은 느낌이면 좋을 것 같은데.

*/