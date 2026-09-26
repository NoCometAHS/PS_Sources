#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        string str;
        cin >> str;

        sort(str.rbegin(), str.rend());
        cout << str << '\n';
    }
    
    return 0;
}

/*
accepted
*/