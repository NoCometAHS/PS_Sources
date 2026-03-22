#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int t, n;
        cin >> t >> n;

        cout << t << ' ';

        int res = 0;
        for (int num = n, d = 1; num; num /= 10, d *= 8) {
            if (num%10 >= 8) {
                res = 0;
                break;
            }

            res += num%10 * d;
        }
        cout << res;

        cout << ' ' << n;

        res = 0;
        for (int num = n, d = 1; num; num /= 10, d *= 16) {
            res += num%10 * d;
        }

        cout << ' ' << res << '\n';
    }
    return 0;
}
