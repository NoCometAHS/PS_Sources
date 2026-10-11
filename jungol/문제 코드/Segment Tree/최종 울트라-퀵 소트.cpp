#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

constexpr LL NodeMx = 1 << 19;
vector<LL> segTree(NodeMx << 1);

void init(vector<LL>& arr, int n) {
    for (int i = 0; i < n; i++) {
        segTree[i+NodeMx] = arr[i];
    }

    for (int i = NodeMx-1; i >= 1; i--) {
        segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
    }
}

void update(int idx, LL v) {
    idx += NodeMx;
    segTree[idx] += v;
    idx >>= 1;
    for (; idx >= 1; idx >>= 1) {
        segTree[idx] = segTree[idx << 1] + segTree[idx << 1 | 1];
    }
}

LL query(int lt, int rt) {
    lt += NodeMx;
    rt += NodeMx;

    LL res = 0;
    while (lt <= rt) {
        if (lt & 1) res += segTree[lt++];
        if (~rt & 1) res += segTree[rt--];

        lt >>= 1;
        rt >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;

    vector<LL> sortedArr(arr), compressed;
    sort(sortedArr.begin(), sortedArr.end());
    for (auto& i : arr) {
        compressed.push_back(lower_bound(sortedArr.begin(), sortedArr.end(), i) - sortedArr.begin());
    }

    LL ans = 0;
    for (auto& i : compressed) {
        ans += query(i+1, n-1);
        update(i, 1);
    }

    cout << ans;
    return 0;
}