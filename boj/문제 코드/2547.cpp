#include "bits/stdc++.h"

using namespace std;
using LL = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        LL res = 0;
        for (int i = 0; i < n; i++) {
            LL num;
            cin >> num;

            res = (res + num) % n;
        }

        if (res) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}