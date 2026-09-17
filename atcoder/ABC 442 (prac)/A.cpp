#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;

    int ans = 0;
    for (auto& i : str) ans += i == 'i' or i == 'j';

    cout << ans;
    
    return 0;
}