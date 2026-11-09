#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int arr[111][333];
    vector<iipair> points;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> arr[i][k];

            if (k != 0) arr[i][k] += arr[i][k-1];

            points.emplace_back(arr[i][k], k);
        }
    }

    sort(points.begin(), points.end());
    
    int ans[333] = {n, }, cur[333] = {n, };
    for (int i = 0; i < points.size(); i++) {
        auto& [tm, range] = points[i];
        cur[range]--; 
        cur[range+1]++;

        set<int> q;
        q.insert(range+1);
        while (i+1 < points.size() && points[i+1].first == tm) {
            i++;

            auto& [t, r] = points[i];
            cur[r]--;
            cur[r+1]++;
            q.insert(r+1);
        }


        for (auto& x : q)
            ans[x] = max(ans[x], cur[x]);
    }

    for (int i = 0; i < m; i++) cout << ans[i] << ' ';

    return 0;
}