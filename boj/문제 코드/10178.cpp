#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int c, v;
        cin >> c >> v;

        cout << "You get " << c / v << " piece(s) and your dad gets " << c % v << " piece(s).\n";
    }
    return 0;
}
