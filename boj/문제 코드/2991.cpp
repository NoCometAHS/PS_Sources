#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < 3; i++) {
        int cur;
        cin >> cur;
        cur--;
        cout << (cur % (a + b) < a) + (cur % (c + d) < c) << '\n';
    }

    return 0;
}
