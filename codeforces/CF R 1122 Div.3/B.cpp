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
        LL a, b, c;
        cin >> a >> b >> c;

        cout << max(abs(a+c - b), abs(a-b)) << '\n';
    }

    return 0;
}

/*



`*/