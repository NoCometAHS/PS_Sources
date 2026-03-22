#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    cin >> n;

    vector<LL> arr(n, 0);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        while (p--) {
            int t;
            cin >> t;
            arr[i]+=t;
        }
    }

    sort(arr.begin(), arr.end());

    LL ans = 0;
    for (int i = 0; i < n-1; i++){
        ans += arr[i];
        arr[i+1] += arr[i];
    }

    cout << ans + arr.back();
    return 0;
}
