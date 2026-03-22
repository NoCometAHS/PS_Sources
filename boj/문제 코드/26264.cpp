#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    string str;
    cin >> str;

    int b = 0, s = 0, i = 0;
    while (i < str.length()) {
        if (str[i] == 's') {
            s++;
            i += 8;
        }
        else {
            b++;
            i += 7;
        }
    }

    if (b >= s) cout << "bigdata? ";
    if (s >= b) cout << "security!";
    
    return 0;
}
