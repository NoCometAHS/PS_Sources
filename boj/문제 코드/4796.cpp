#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int l, p, v;
    cin >> l >> p >> v;

    int t = 1;
    while (l) {
        cout << "Case " << t++ << ": " <<  v / p * l + min(v % p, l) << '\n';

        cin >> l >> p >> v;
    } 
    return 0;
}
