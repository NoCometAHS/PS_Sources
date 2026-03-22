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

    while (n--) {
        string num;

        cin >> num;

        if ((num.back() - '0') % 2) cout << "odd";
        else cout << "even";
        cout << '\n';
    }
    return 0;
}
