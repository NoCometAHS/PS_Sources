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

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n * 5; k++) {
            cout << "@";
        }
        cout << '\n';
    }

    
    for (int i = 0; i < n  * 4; i++) {
        for (int k = 0; k < n; k++) {
            cout << "@";
        }
        cout << '\n';
    }
    return 0;
}
