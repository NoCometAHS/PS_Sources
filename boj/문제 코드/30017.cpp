#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    cin >> a >> b;

    if (a <= 1 || b == 0) {
        cout << 0;
        return 0;
    }

    a-=2;
    b--;

    cout << 3 + min(a, b)*2;
    return 0;
}
