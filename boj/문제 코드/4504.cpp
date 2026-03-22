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

    int p;
    cin >> p;

    while (p) {
        if (p % n) {
            cout << p << " is NOT a multiple of " << n << ".\n";
        }
        else {
            cout << p << " is a multiple of " << n << ".\n";    
        }
        
        cin >> p;
    }
    return 0;
}
