#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, w, h, l;
    cin >> n >> w >> h >> l;

    cout << min(n, (w/l) * (h/l));


    return 0;
}
