#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (auto& i : arr) {
        cin >> i;
    }

    sort(arr.begin(), arr.end());

    while(m--) {
        int q;
        cin >> q;

        auto res = lower_bound(arr.begin(), arr.end(), q);

        if (res == arr.end() || *res != q) {
            cout << -1 << '\n';
        }
        else {
            cout << res - arr.begin() << '\n';
        }
    }
    return 0;
}
