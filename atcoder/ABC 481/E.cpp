#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;


ll ccw(iipair a, iipair b) {
    return a.first*b.second - a.second * b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<iipair> up, down;
        for (int i = 0, x, y; i < n; i++) {
            cin >> x >> y;

            if (y > 0 or (y == 0 and x >= 0)) up.emplace_back(x, y);
            else down.emplace_back(x, y);
        } 

        sort(up.begin(), up.end(), [&](const iipair& a, const iipair& b) {
            return ccw(a, b) > 0;
        });
        sort(down.begin(), down.end(), [&](const iipair& a, const iipair& b) {
            return ccw(a, b) > 0;
        });

        vector<iipair> arr(up);
        for (auto& i : down) arr.push_back(i);

        ll lt = 0, rt = 0, cnt = 1, ans = 0;
        auto next = [&](const ll& idx) {
            return (idx + 1) % n;
        };

        for (int i = 0; i < n; i++) {
            if (cnt == 0) {rt = lt, cnt = 1;}

            while (ccw(arr[lt], arr[next(rt)]) > 0) {
                rt = next(rt);
                cnt++;
            }
            
            ans = max({ans, cnt, n-cnt});

            lt++;
            cnt--;
        }

        cout << ans << '\n';
    }
    return 0;
}