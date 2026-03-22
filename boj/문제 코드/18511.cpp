#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int dfs(int n, int cur, vector<int>& arr) {
    if (cur > n) {
        return -1;
    }

    int ret = cur;
    for (auto& i : arr) {
        ret = max(ret, dfs(n, cur * 10 + i, arr));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int num, n;
    cin >> num >> n;

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    cout << dfs(num, 0, arr);

    return 0;
}
