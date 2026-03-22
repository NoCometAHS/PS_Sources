#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c;
    cin >> a >> b >> c;

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int k = 0; k < 3; k++) {
            int A,B,C;
            cin >> A >> B >> C;

            res += A*a + B*b + C*c;
        }

        ans = max(ans, res);
    }

    cout << ans;
    return 0;
}
