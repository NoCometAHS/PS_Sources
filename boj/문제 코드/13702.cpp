#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int func(LL ml, vector<LL>& arr) {
    int ret = 0;
    for (auto& i : arr) ret +=  i / ml;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, m;
    cin >> n >> m;

    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;

    LL lt = 0, rt = (1LL<<31) - 1, mid;
    LL ans = 0;
    while (lt <= rt) {
        mid = (lt + rt) / 2;
        if (func(mid, arr) >= m) {
            lt = mid+1;
            ans = mid;
        }
        else {
            rt = mid-1;
        }
    }

    cout << ans;

    return 0;
}
