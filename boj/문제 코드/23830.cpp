#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    cin >> n;

    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;

    LL p, q, r, S;
    cin >> p >> q >> r >> S;

    LL lt = 1, rt = 1e11, mid;
    LL ans = -1;

    while (lt <= rt) {
        mid = (lt + rt) / 2;

        LL res = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < mid) res += arr[i] + q;
            else if (mid + r < arr[i]) res += arr[i] - p;
            else res += arr[i];
        }

        if (res < S) {
            lt = mid + 1;
        }
        else {
            ans = mid;
            rt = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
