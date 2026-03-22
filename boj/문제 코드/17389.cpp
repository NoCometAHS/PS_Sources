#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int ans = 0, b = 0;

    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        if (ch == 'O') {
            ans += i + 1 + b;
            b++;
        }
        else {
            b = 0;
        }
    }

    cout << ans;
    return 0;
}
