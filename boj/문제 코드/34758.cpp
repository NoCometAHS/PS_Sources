#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x, y;
    cin >> x >> y;

    int tc;
    cin >> tc;
    while (tc--) {
        int a, b;
        cin >> a >> b;

        cout <<  1 - ((x == a) || (y == b)) << '\n';
    }
    return 0;
}
