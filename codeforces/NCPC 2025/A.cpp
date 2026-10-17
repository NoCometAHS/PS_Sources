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

    for (int a = -999; a < 1000; a++) {
        for (int b = - 999; b < 1000; b++) {
            if (a + b != n) continue;

            cout << a << ' ' << b;
            return 0;
        }
    }

    return 0;
}