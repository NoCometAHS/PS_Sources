#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cur = 0;

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;

        cur += b - a;

        ans = max(ans, cur);
    }

    cout << ans;
    return 0;
}
