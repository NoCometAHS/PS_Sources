#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double n;
    cin >> n;

    cout << fixed;
    cout.precision(10);
    cout << n* sqrt(3) / 2 * n / 2;
    return 0;
}
