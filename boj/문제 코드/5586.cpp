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

    int joi = 0, ioi = 0;
    for (int i = 0; i < str.length() - 2; i++) {
        if (str[i] == 'J') {
            joi += (str[i+1] == 'O' && str[i+2] == 'I');
        }
        else if (str[i] == 'I') {
            ioi += (str[i+1] == 'O' && str[i+2] == 'I');
        }
    }

    cout << joi << '\n' << ioi;
    return 0;
}
