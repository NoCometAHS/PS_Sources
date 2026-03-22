#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << (c + d) / (a - b);
    return 0;
}
