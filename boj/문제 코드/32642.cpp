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
    LL ans = 0;
    cin >> n;

    int cur = 0;
    while (n--) {
        int a;
        cin >> a;

        cur += (a ? 1 : -1);
        ans += cur;
    }
    cout << ans;
    return 0;
}
