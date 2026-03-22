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

    string korea = "KOREA";
    int ans = 0;
    for (int i = 0, k =0; i < str.length(); i++) {
        if (str[i] == korea[k]) {
            ans++;
            k = (k+1) % 5;
        }
    }

    cout << ans;
    
    return 0;
}
