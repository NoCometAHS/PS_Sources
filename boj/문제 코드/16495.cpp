#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;

    LL ans = 0;
    for (LL i = str.length() - 1, d = 1; i >= 0; i--, d *= 26) {
        ans += (str[i] - 'A' + 1)*d;
    }

    cout << ans;
    return 0;
}
