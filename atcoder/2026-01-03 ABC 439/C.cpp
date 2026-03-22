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

    vector<LL> res;
    vector<int> count(10000001, 0); 
    for (LL x = 1; x*x < n; x++) {
        for (LL y = x + 1; x*x + y*y <= n; y++) {
            res.push_back(x*x + y*y);
            count[x*x + y*y]++;
        }
    }

    vector<LL> ans;
    for (auto& i: res) {
        if (count[i] != 1) continue;
        ans.push_back(i);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto& i : ans) cout << i << ' ';

    return 0;
}
