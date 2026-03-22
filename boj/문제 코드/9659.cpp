#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL a;
    cin >> a;

    cout << (a % 2 ? "SK" : "CY");
    
    return 0;
}


//
// 1 2 3 4 5 6 7
// t f t f t