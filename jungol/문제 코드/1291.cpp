#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    int s, e;
    cin >> s >> e;

    while (min(s,e) < 2 || max(s,e) > 9) {
        cout << "INPUT ERROR!\n";
        cin >> s >> e;
    }

    int d = (s < e ? 1 : -1);
    int st = s;

    if (s > e) swap(s,e);

    for (int i = 1; i < 10; i++) {
        for (int k = st; s <= k && k <= e; k += d) {
            printf("%d * %d = %2d   ",k, i, k*i);
        }
        cout << '\n';
    }


    return 0;
}