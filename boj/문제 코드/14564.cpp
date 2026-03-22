#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, a;
    cin >> n >> m >> a;

    int x;
    cin >> x;
    while (x != m/2+1) {
        x -= m/2+1;

        a = (a + n + x - 1) % n + 1;

        cout << a << '\n';
        cin >> x;
    }

    cout << 0;
    return 0;
}
