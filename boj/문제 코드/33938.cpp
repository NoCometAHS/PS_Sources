#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<int> arr(2, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 1e9;
    for (int i = 0; i < 2000; i++) {
        for (int k = 0; k < 2000; k++) {
            if (arr[0] * i + arr[1] * k != m) continue;

            ans = min(ans, i + k);
        }
    }

    if (ans == 1e9) cout << -1;
    else cout << ans;
    
    return 0;
}