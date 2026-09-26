#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, d;
    cin >> m >> d;

    if (m == 1 and d == 7 or m == 3 and d == 3 or m == 5 and d == 5 or m == 7 and d == 7 or m == 9 and d == 9) {
        cout << "Yes";
    }
    else cout << "No";

    return 0;
}