#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int dx[] = {-1, 0, 1};

    int n;
    cin >> n;

    TwoVector<int> arr(n, vector<int>(3));
    for (auto& v : arr) {
        for (auto& i : v) cin >> i;
    }

    TwoVector<int> MxDp(n, vector<int>(3, -1)), MnDp(n, vector<int>(3, 1e9));

    for (int i = 0; i < 3; i++) {
        MnDp[0][i] = MxDp[0][i] = arr[0][i];
    }

    for (int i = 0; i < n-1; i++) {
        for (int k = 0; k < 3; k++) {
            for (int d = 0; d < 3; d++) {
                int idx = k + dx[d];

                if (idx < 0 || idx >= 3) continue;

                MxDp[i+1][idx] = max(MxDp[i+1][idx], MxDp[i][k] + arr[i+1][idx]);
                MnDp[i+1][idx] = min(MnDp[i+1][idx], MnDp[i][k] + arr[i+1][idx]);
            }
        }
    }

    int ans1 = -1, ans2 = 1e9;
    for (int i = 0; i < 3; i++) {
        ans1 = max(ans1, MxDp[n-1][i]);
        ans2 = min(ans2, MnDp[n-1][i]);
    }
    cout << ans1 << ' ' << ans2;


    return 0;
}
