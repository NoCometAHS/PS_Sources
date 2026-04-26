#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int b, t;
    char op;

    cin >> b >> op >> t;

    while (t) {

        if (op == 'W') {
            if  (b - t < -200) {
                cout << "Not allowed\n";
            }
            else {
                cout << b - t << '\n';
            }
        }
        else {
            cout << b + t << '\n';
        }

        cin >> b >> op >> t;
    }

    return 0;
}
