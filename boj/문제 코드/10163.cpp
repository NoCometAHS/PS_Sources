#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    TwoVector<int> board(1010, vector<int>(1010, 0));

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;

        for (int k = 0; k < w; k++) {
            for (int p = 0; p < h; p++) {
                board[y+p][x+k] = i;
            }
        }
    }

    vector<int> ans(n+1, 0);

    for (int i = 0; i < 1010; i++) {
        for (int k = 0; k < 1010; k++) {
            ans[board[i][k]]++;
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}
