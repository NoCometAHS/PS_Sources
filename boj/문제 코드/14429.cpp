#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    int ansNum, ans = 1e9;
    for (int i = 1; i <= n; i++) {
        int j, m;
        cin >> j >> m;

        int r = (j-1) % (1 + m);
        j -= r;

        int t = (j / (1 + m)) * 2 + 2;

        if (ans > t) {
            ans = t;
            ansNum = i;
        }
    }

    cout << ansNum << ' ' << ans;
    return 0;
}