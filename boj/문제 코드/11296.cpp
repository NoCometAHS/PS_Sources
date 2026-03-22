#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<char, int> m({{'R', 45},{'G', 30},{'B', 20},{'Y', 15},{'O', 10},{'W', 5}});
    while (n--) {
        double cost;
        char dot, coupon, pay;
        cin >> cost >> dot >> coupon >> pay;

        double discount = m[dot];
        cost = cost - cost * discount / 100;

        if (coupon == 'C') {
            cost  = cost - cost / 20;
        }

        cout << fixed;
        cout.precision(2);
        if (pay == 'C') {
            cost *= 10;
            cost -= 0.1;
            cost = round(cost);
            cost /= 10;

            cout << '$' << cost << '\n';
        }
        else {
            cost *= 100;
            cost = round(cost);
            cost /= 100;

            cout << '$' << cost << '\n';
        }
    }
    return 0;
}
