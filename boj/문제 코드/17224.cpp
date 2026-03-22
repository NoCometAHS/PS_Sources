#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, l, k;
    cin >> n >> l >> k;

    vector<iipair> arr(n);
    for (auto& [a, b] : arr) cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (k == 0) break;

        if (arr[i].second <= l) {
            ans += 140;
            arr[i] = {999,999};
            k--;
        }
    }

        for (int i = 0; i < n; i++) {
        if (k == 0) break;

        if (arr[i].first <= l) {
            ans += 100;
            arr[i] = {999,999};
            k--;
        }
    }

    cout << ans;

    return 0;
}
