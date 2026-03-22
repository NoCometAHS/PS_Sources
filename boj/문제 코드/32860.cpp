#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    int n;
    cin >> s >> n;

    string p;
    if (n <= 26) {
        p += 'A' + n - 1;
    }
    else {
        n -= 27;
        p = "aa";
        for (int i = 0; i < n; i++) {
            p.back()++;

            if (p.back() > 'z') {
                p.back() = 'a';
                p.front()++;
            }
        }
    }



    cout << "SN " << s << p;
    return 0;
}

/*
a가 0이면서 1이 될 때가 있어서 문제가 되는데.
A - Z
1 - 26

aa - az
27 - 52
*/