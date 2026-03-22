#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    cin >> a >> b;

    int i = 1;
    while (a != "END") {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        cout << "Case " << i++ << ": ";
        if (a == b) {
            cout << "same\n";
        }
        else {
            cout << "different\n";
        }
        
        cin >> a >> b;
    }
    return 0;
}
