#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int days[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;

    while (tc--) {
        int y, m;
        cin >> y >> m;
        
        if (m == 1) {
            cout << y-1 << " 12 31";
        }
        else if (m == 3) {
            if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0) {
                cout << y << " 2 29";
            }
            else {
                cout << y << " 2 28";
            }
        }
        else {
            cout << y << ' ' << m-1 << " " << days[m-1];
        }
        cout << '\n';
    }

    return 0;
}
