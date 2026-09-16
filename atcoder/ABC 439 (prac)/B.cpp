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

    vector<bool> arr(2027, false);

    while (n != 1 and !arr[n]) {
        arr[n] = true;

        int t = 0;
        while (n) {
            t += (n % 10) *(n % 10);
            n /=10;
        }
        n = t;
    }


    if (n == 1) cout << "Yes";
    else cout << "No";
    return 0;
}