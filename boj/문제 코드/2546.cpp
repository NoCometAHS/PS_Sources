#include "bits/stdc++.h"

using namespace std;
using LL = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;;

        vector<int> c(n);
        double cAve = 0, eAve = 0;

        for (auto& i : c) {
            cin >> i;
            cAve += i;
        }

        for (int i = 0; i < m; i++) {
            int s;
            cin >> s;

            eAve += s;
        }

        cAve /= n, eAve /= m;

        int ans = 0;
        for (auto& i : c) {
            ans += i < cAve && i > eAve;
        }

        cout << ans << '\n';
    }
    return 0;
}