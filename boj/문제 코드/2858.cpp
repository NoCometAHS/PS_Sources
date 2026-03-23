#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, b;
    cin >> r >> b;

    for (int w = 3; w < r; w++) {
        for (int l = 3; (w-2)*2 + l*2 <= r; l++) {
            if ((w-2) * (l-2) != b) continue;

            cout << l << ' ' << w;
            return 0;
        }
    }
    return 0;
}