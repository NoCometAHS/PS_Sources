#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string str;
    cin >> n >> str;

    int ans = 0;
    for (auto& i : str) ans += i - 'A' + 1;
    
    cout << ans;

    return 0;
}
