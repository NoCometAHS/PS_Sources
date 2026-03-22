#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tc;
    cin >> tc;

    while (tc--) {
        int x, y;
        cin >> x >> y;

        if (x <= 23 && y <= 59) {
            cout << "Yes ";
        }
        else {
            cout << "No ";
        }

        if (1 <= x && x <= 12 && 1<= y && y <= days[x]) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }

    }
    return 0;
}
