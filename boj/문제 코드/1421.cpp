#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, c, w;
    cin >> n >> c >> w;

    vector<LL> arr(n);
    LL mx=-1;
    for (auto& i : arr) {
        cin >> i;
        mx = max(mx, i);
    }

    LL ans = 0;
    for (int i = 1; i <= mx; i++) {
        LL test = 0;
        for (int k = 0; k < n; k++) {
            LL t = arr[k] / i;
            LL earn = i*t*w, cost = (arr[k] % i ? t : t-1) * c;

            if (earn > cost) test += earn - cost;
        }

        ans = max(ans, test);
    }

    cout << ans;

    return 0;
}
