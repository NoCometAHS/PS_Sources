#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using sipair = pair<string,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<sipair> arr(n);

    int ans = 0, jinjuCost;
    for (auto& [s, i] :  arr) {
        cin >> s >> i;

        if (s == "jinju") jinjuCost = i;
    }

    cout << jinjuCost << '\n';

    for (auto& [s, i] : arr) {
        if (i > jinjuCost) ans++;
    }
    cout << ans;
    
    return 0;
}
