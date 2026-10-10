#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<short,short>;

template<typename t>
using TwoVector = vector<vector<t>>;


short idx[5001][5001];
short dp[5001][5001]; // dp[k][i], i번 원소가 마지막이고 k번 원소가 그 다음일때의 최대 길이.
iipair arr[5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    memset(idx, -1, sizeof(idx));

    int r, c, n;
    cin >> r >> c >> n;

    for (int i = 0; i < n; i++) {
        auto& [x, y] = arr[i];
        cin >> y >> x;
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        auto& [x, y] = arr[i];
        idx[y][x] = i;
    }

 
    short ans = 0;
    for (int i = 1; i < n; i++) {
        for (int k = i-1; k >= 0; k--) {
            int dx = arr[i].first - arr[k].first, dy = arr[i].second - arr[k].second;
            int ppx = arr[k].first - dx, ppy = arr[k].second - dy;
            
            if (ppx <= 0 || ppy <= 0 || ppy > r) {
                dp[k][i] = 2;
            }
            else {
                if (idx[ppy][ppx] == -1) continue;
                else if (dp[idx[ppy][ppx]][k]) {
                    dp[k][i] = dp[idx[ppy][ppx]][k] + 1;

                    int nx = arr[i].first + dx, ny = arr[i].second + dy;
                    if (nx > c ||  ny > r || ny <= 0) {
                        ans = max(ans, dp[k][i]);
                    }
                }
            }
        }
    }


    cout << ans;

    


    return 0;
}