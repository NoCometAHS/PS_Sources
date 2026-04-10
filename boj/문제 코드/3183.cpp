#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int days[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    int d, m, y;
    cin >> d >> m >> y;
    while (d != 0 || m != 0 || y != 0) {
        bool isLeap = (y % 4 == 0 && y % 100) || y % 400 == 0;
        bool ans = true;

        if (m <= 0 || m > 12) {
            ans = false;
        }
        else if (d <= 0 || d > days[isLeap][m]) {
            ans = false;
        }

        cout << (ans ? "Valid" : "Invalid") << '\n';
        cin >> d >> m >> y;
    }
    return 0;
}