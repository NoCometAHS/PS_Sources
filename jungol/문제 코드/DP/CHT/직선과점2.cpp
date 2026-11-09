#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

constexpr ll inf = 1 << 18;

struct Line {
    ll a, b;
    Line(ll a = 0, ll b = -inf): a(a), b(b) {}
    ll f(ll x) {
        return a*x + b;
    }
};

struct Node{
    Line line;
    ll l, r;

    Node() : line(), l(-1), r(-1) {}
};


vector<Node> T(1);

void add(Line line, int node, ll lt, ll rt) {
    Line lo(T[node].line), hi(line);
    
    if (lo.f(lt) > hi.f(lt)) swap(lo, hi);
    if (lo.f(rt) <= hi.f(rt)) {
        T[node].line = hi;
        return;
    }

    ll m = (lt + rt) >> 2;
    
    if (lo.f(m) >= hi.f(m)) {
        T[node].line = lo;
        if (T[node].l == -1) {
            T[node].l = T.size();
            T.emplace_back();
        }

        add(hi, T[node].l, lt, m);
    }
    else {
        T[node].line = hi;
        if (T[node].r == -1) {
            T[node].r = T.size();
            T.emplace_back();
        }

        add(lo, T[node].r, m+1, rt);
    }
}

ll query(ll x, int node, ll lt, ll rt) {
    ll ret = (node == -1 ? -inf : T[node].line.f(x));
    if (node == -1) return ret;

    ll m = (lt + rt) >> 2;
    if (x <= m) {
        return max(ret, query(x, T[node].l, lt, m));
    }
    else {
        return max(ret, query(x, T[node].r, m+1, rt));
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (n--) {
        ll a, b;
        cin >> a >> b;

        add(Line(a, b), 0, -1e9, 1e9);
    }

    while (m--) {
        int q;
        cin >> q;

        if (q == 1) {
            ll x;
            cin >> x;

            cout << query(x, 0, -1e9, 1e9) << '\n';
        }
        else {
            ll a, b;
            cin >> a >> b;

            add(Line(a, b), 0, -1e9, 1e9);
        }
    }
    

    return 0;
}