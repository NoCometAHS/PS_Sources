#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        int d = n % 100;
        if ((n+1) % d ) {
            cout << "Bye\n";
        }
        else cout << "Good\n";
    }
    return 0;
}
