#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    auto T = [](int n) {return n*(n+1)/2;};

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        int w = 0;

        for (int k = 1; k <= n; k++) {
            w += k * T(k+1);
        }

        cout << w << '\n';
    }
    return 0;
}