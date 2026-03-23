#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    double p = 0, c = 0;
    while (n--) {
        string s, g;
        int t;
        cin >> s >> t >> g;

        p += t;

        double temp = 0;
        if (g[0] == 'A') temp = 4;
        else if (g[0] == 'B') temp = 3;
        else if (g[0] == 'C') temp = 2;
        else if (g[0] == 'D') temp = 1;

        if (g.length() > 1) {
            if (g[1] == '+') temp += 0.3;
            else if (g[1] == '-') temp -= 0.3;
        }

        c += temp * t;
    }

    cout << fixed;
    cout.precision(2);

    cout << round(c / p * 100) / 100;
    return 0;
}