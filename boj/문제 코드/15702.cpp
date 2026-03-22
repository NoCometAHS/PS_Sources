#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<int> scores(n);
    for (auto& i : scores) cin >> i;

    int ans = 1e9, mx = -1e9;
    while (m--) {
        int num;
        cin >> num;

        int cur = 0;
        for (int i = 0; i < n; i++) {
            char r;
            cin >> r;

            if (r == 'O') {
                cur += scores[i];
            }
        }

        if (mx < cur) {
            mx = cur;
            ans = num;
        }
        else if (mx == cur) {
            ans = min(ans, num);
        }
    }

    cout << ans << ' ' << mx;
    return 0;
}
