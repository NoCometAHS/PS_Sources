#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL a, b;
    cin >> a >> b;

    if (a > b) swap(a,b);

    cout << max(0LL, b - a - 1) << '\n';
    for (LL i = a+1; i < b; i++) cout << i << ' ';

    return 0;
}
