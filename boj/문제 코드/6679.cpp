#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 1000; i < 10000; i++) {
        int a = 0, b = 0, c = 0;

        for (int k = i; k; k /= 10) a += k % 10;
        for (int k = i; k; k /= 12) b += k % 12;
        for (int k = i; k; k /= 16) c += k % 16;

        if (a != b || b != c) continue;

        cout << i << '\n';
    }
    return 0;
}
