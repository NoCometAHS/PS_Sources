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
    string str;

    cin >> n >> str;

    for (int i = 0; i < str.length(); i += n) cout << str[i];
    
    return 0;
}
