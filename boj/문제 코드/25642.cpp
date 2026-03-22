#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    cin >> a >> b;

    bool yt = false;
    while (true) {
        b += a;

        if (b >= 5) {
            yt = true;
            break;
        }

        a += b;

        if (a >= 5) {
            break;
        }
    }

    cout << (yt ? "yt" : "yj");
    
    return 0;
}
