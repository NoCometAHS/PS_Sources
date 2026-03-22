#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        string str;
        cin >> n >> str;

        str.erase(str.begin()+(n-1));
        cout << str << '\n';
    }
    return 0;
}
