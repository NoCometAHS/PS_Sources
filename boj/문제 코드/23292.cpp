#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int func(int date1, int date2) {
    int y = 0, m = 0, d = 0;

    for (int i = 0; i < 2; i++) {
        int res = (date1%10 - date2%10);
        d += res*res;
        date1/=10;
        date2/=10;
    }
    for (int i = 0; i < 2; i++) {
        int res = (date1%10 - date2%10);
        m += res*res;
        date1/=10;
        date2/=10;
    }
    for (int i = 0; i < 4; i++) {
        int res = (date1%10 - date2%10);
        y += res*res;
        date1/=10;
        date2/=10;
    }

    return y*m*d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int base, n;
    cin >> base >> n;

    int ans;
    cin >> ans;
    n--;
    while (n--) {
        int date;
        cin >> date;

        int res1 = func(base, ans), res2 = func(base, date);
        if (res1 < res2) {
            ans = date;
        }
        else if (res1 == res2) {
            ans = min(ans, date);
        }
    }

    cout << ans;
    return 0;
}
