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

    if (!n) {
        cout << 0;
        return 0;
    }
    string ans;
    while (n) {
        int res = n % m;

        if (res >= 10) {
            ans.push_back('A' + res - 10);
        }
        else {
            ans.push_back('0' + res);
        }

        n /= m;
    }

    reverse(ans.begin(), ans.end());

    
    cout << ans;
    return 0;
}
