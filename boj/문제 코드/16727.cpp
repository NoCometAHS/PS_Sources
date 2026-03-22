#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d, s1 = 0, s2 = 0;

    cin >> a >> b >> c >> d;
    s1 += a + d, s2 += b + c;

    if (s1 < s2) {
        cout << "Esteghlal";
    }
    else if (s1 > s2) {
        cout << "Persepolis";
    }
    else {
        if (d > b) {
            cout << "Persepolis";
        }
        else if (d < b) {
            cout << "Esteghlal";
        }
        else {
            cout << "Penalty";
        }
    }

    return 0;
}
