#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;

    while (tc--) {
        double a, b;
        cin >> a >> b;

        int cnt;
        for (cnt = 1; b*cnt < a; cnt++);

        LL ans = 0;
        for (LL i = cnt + cnt-1; i > 0; i -= 2) {
            ans += i;
        }

        cout << ans << '\n';
    }
    return 0;
}
