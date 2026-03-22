#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    cin >> a >> b;

    while (a != "0" || b != "0" ) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int ans = 0, carry = 0, i;

        for (i = 0; i < a.length() && i < b.length(); i++) {
            if (a[i] + b[i] - '0' + carry <= '9') {
                carry = 0;
                continue;
            }

            carry = 1;
            ans++;
        }

        while (i < a.length()) {
            if (a[i]  + carry <= '9') {
                carry = 0;
                continue;
            }

            carry = 1;
            ans++;
            i++;
        }

        while (i < b.length()) {
            if (b[i]  + carry <= '9') {
                carry = 0;
                continue;
            }

            carry = 1;
            ans++;
            i++;
        }


        cout << ans << '\n';

        cin >> a >> b;
    }

    return 0;
}
