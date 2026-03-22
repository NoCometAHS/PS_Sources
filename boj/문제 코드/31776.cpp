#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1);
        else if (b == -1) {
            if (c == -1) ans++;
        }
        else if (c == -1) {
            if (a <= b) ans++;
        }
        else {
            if (a <= b && b <= c) ans++;
        }
    }

    cout << ans;
    return 0;
}