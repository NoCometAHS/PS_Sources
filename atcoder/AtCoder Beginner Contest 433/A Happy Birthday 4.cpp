#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> b >> a >> c;

    if (b < a*c) {
        cout << "No";
    }
    else if ((b - a*c) % (c-1) == 0 ) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}

// (x+a)*z = y+a
//x*z + a*z = y + a
//x*z + a*(z-1)= y
// a*(z-1) = y - x*z