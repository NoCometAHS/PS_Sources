#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;

    for (auto i : str) {
        i -= 3;
        if (i < 'A') i = 'Z' - ('A' - i) + 1;

        cout << i;
    }
    return 0;
}
