#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, m;
    cin >> n >> m;

    LL ans = 1;
    while (n--) {
        LL num;
        cin >> num;

        ans = ans * num % m;
    }

    cout << ans;
    return 0;
}
