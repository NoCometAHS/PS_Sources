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

    vector<int> res;
    for (int i = 0; i < 8; i++) {
        res.push_back(a[i] - '0');
        res.push_back(b[i] - '0');
    }

    for (int i = 0; res.size() > 2; i++) {
        vector<int> t;

        for (int k = 0; k < res.size() - 1; k++) {
            t.push_back((res[k] + res[k+1]) % 10);
        }

        swap(t, res);
    }

    cout << res[0] <<  res[1];
    return 0;
}
