#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n < 0) {
        cout << 32;
    }
    else if (n == 0)
    {
        cout << 1;
    }
    else {
        int ans = 31;
        while (((n >> ans) & 1) != 1 && ans >= 0) ans--;
        cout << ans + 1;
    }

    return 0;
}
