#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k, t;
    cin >> n  >> k >> t;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;

        if (t > k) {
            t = t + d - abs(t - k);
        }
        else if (t < k) {
            t = t + d + abs(t - k);
        }
        else {
            t = t + d;
        }

        ans += abs(t - k);
    }

    cout << ans;

    return 0;
}
