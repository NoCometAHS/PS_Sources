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

    for (int i = 0; i < 100000; i++) {
        int res = 0;
        while (n) {
            res += (n%10)*(n%10);
            n/=10;
        }

        n = res;
    }

    if (n == 1) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}
