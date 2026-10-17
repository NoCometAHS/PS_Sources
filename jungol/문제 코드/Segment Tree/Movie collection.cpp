#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll, ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

constexpr ll SZ = 1 << 18;
ll T[SZ << 1];

void update(int idx, int v) {
    idx += SZ;

    T[idx] = v;

    while (idx >>= 1) T[idx] = T[idx << 1] + T[idx << 1 | 1];
}

ll sum(int lt, int rt) {
    ll res = 0;
    for (lt += SZ, rt += SZ; lt <= rt; lt >>= 1, rt >>= 1 ) {
        if (lt & 1) res += T[lt++];
        if (~rt & 1) res += T[rt--];
    }

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        vector<int> pos(n+1);
        int top = n-1;
        for (int i = 1; i <= n; i++) {
            pos[i] = n-i;
            update(pos[i], 1);
        }

        while (m--) {
            int num;
            cin >> num;

            cout << sum(pos[num] + 1, SZ-1) << ' ';

            update(pos[num], 0);
            update(++top, 1);
            pos[num] = top;
        }
        cout << '\n';

        memset(T, 0, sizeof(T));
    }

    return 0;
}