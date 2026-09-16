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

    vector<int> cnt(n+1 , 0);

    for (LL x = 1; x*x < n; x++) {
        for (LL y = x+1; x*x + y*y <= n; y++) {
            cnt[x*x + y*y]++;     
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) ans.push_back(i);
    }
    
    cout << ans.size() << '\n';
    for (const auto& i : ans) cout << i << ' ';

    return 0;
}