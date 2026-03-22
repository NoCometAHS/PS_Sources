#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    int r;
    int a = 0;
    while (true) {
        a++;
        cout << "? A " << a << endl;

        cin >> r;

        if (r) break;
    }
    
    int b = 0;
    while (true) {
        b++;
        cout << "? B " << b << endl;

        cin >> r;

        if (r) break;
    }

    cout << "! " << a + b << endl;
    
    return 0;
}
