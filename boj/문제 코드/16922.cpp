#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    TwoVector<bool> chk(2, vector<bool>(50*22, false));

    chk[0][0] = true;

    int unit[4] = {1, 5, 10, 50};
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 1100; k++) {
            if (!chk[0][k]) continue;

            for (int u = 0; u < 4; u++) {
                if (k + unit[u] >= 1100) continue;

                chk[1][k+unit[u]] = true;
            }

            chk[0][k] = false;
        }

        swap(chk[0], chk[1]);
    }

    int ans = 0;
    for (int i = 0; i < 1100; i++){
        ans += chk[0][i];
    }

    cout << ans;
    return 0;
}
