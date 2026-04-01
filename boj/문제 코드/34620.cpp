#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int p, c;
    cin >> c >> p;

    if (p != (p & -p)) {
        cout << -1;
        return 0;
    }

    string ans;
    while (p != 1 || c != 0) {
        if (c >= p) {
            c -= p;
            ans.push_back('G');
        }
        else {
            p /= 2;
            ans.push_back('K');
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}