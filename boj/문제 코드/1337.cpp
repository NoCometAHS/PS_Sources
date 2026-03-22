#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& i: arr) cin >> i;

    sort(arr.begin(), arr.end());

    int ans = 4;
    for (int i = 0; i < n; i++) {
        set<int> chk;
        for (int k = 1; k <= 4; k++) chk.insert(arr[i]+k);

        int cnt = 0;
        for (int k = 1; k <= 4 && i + k < n; k++) {
            cnt += chk.count(arr[i+k]);
        }

        ans = min(ans, 4 - cnt);
    }

    cout << ans;
    return 0;
}
