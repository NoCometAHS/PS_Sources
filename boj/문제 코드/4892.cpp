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

    int i = 1;

    while (n) {

        cout << i++ << ". ";
        if (n*3 % 2) cout << "odd ";
        else cout << "even ";

        cout << (n*3+1)/2 * 3 / 9 << '\n';
        cin >> n;
    }
    return 0;
}
