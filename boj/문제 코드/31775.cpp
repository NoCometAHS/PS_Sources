#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    set<char> a{'l', 'k', 'p'}, b;


    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;

        b.insert(s.front());
    }


    if (a == b) {
        cout << "GLOBAL";
    }
    else {
        cout << "PONIX";
    }
    return 0;
}
