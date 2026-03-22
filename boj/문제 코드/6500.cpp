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

    while (n) {
        unordered_set<int> chk{n};
        n = (n * n) / 100 % 10000;

        while (!chk.count(n)) {
            chk.insert(n);

            n = (n * n) / 100 % 10000;
        }

        cout << chk.size() << '\n';

        cin >> n;
    }
    return 0;
}
