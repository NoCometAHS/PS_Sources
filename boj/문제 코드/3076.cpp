#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    for (int i = 0; i < n * a; i++) {
        for (int k = 0; k < m * b; k++) {
            int y = i / a, x = k / b;

            if ((x + y) % 2) {
                cout << ".";
            }
            else {
                cout << "X";
            }
        }
        cout << '\n';
    }
    
    return 0;
}
