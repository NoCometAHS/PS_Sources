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

    string res;
    for (auto& i : a) {
        if ('0' <= i && i <= '9'  ) continue;
        res += i;
    }

    if (res.find(b) != string::npos) {
        cout << 1;
    }
    else {
        cout << 0;
    }
    return 0;
}
