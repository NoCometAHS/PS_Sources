#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        LL a, n;
        cin >> a >> n;

        string to;
        while (a) {
            if (a % n >= 10) {
                to.push_back(a % n + 'A');
            }
            else {
                to.push_back(a % n + '0');
            }

            a /= n;
        }

        bool ans = true;
        for (int lt = 0, rt = to.length()-1; lt < rt; lt++, rt--) {
            if (to[lt] != to[rt]) ans = false;
        }

        cout << ans << '\n';

    }
    return 0;
}
