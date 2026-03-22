#include "bits/stdc++.h"

using namespace std;

int main(){

    int n;
    cin >> n;

    while (n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += (n - i + 1) * (n - i + 1);
        }

        cout << ans << '\n';

        cin >> n;
    }
    return 0;
}