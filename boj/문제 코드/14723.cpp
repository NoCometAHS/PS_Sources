#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int par = 1, ch = 1;
    while (--n) {
        if (ch == 1) {
            ch = par+1;
            par = 1;
        }
        else {
            ch--;
            par++;
        }
    }

    cout << ch << ' ' << par;
    return 0;
}
