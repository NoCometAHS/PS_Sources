#include "bits/stdc++.h"

using namespace std;
using LL = unsigned long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    cin >> n;

    cout << __builtin_popcountll(n);
    return 0;
}
