#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<bitset<20>> arr(n);

    while (m--) {
        int q, i, x;
        cin >> q >> i;
        i--;

        if (q == 1) {
            cin >>  x;
            x--;

            arr[i].set(x);
        }
        else if (q == 2) {
            cin >> x;
            x--;

            arr[i].reset(x);
        }
        else if (q == 3) {
            arr[i] <<= 1;
        }
        else {
            arr[i] >>= 1;
        }
    }

    set<int> ans;
    for (int i = 0; i < n; i++) {
        ans.insert(arr[i].to_ulong());
    }

    cout << ans.size();
    return 0;
}
