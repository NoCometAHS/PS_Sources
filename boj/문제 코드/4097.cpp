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

    while (n) {
        int ans = -1e9, cur = 0;
        while (n--) {
            int num;
            cin >> num;

            cur += num;
            ans = max(ans, cur);

            if (cur < 0) cur = 0;
        }

        cout << ans << '\n';
        cin >> n;
    }
    return 0;
}
