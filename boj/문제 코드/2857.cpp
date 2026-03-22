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
    int num = 1, ans = 0;
    while (cin >> str) {
        for (int i = 0; i < str.length() - 2; i++) {
            if (str[i] == 'F' && str[i+1] == 'B' && str[i+2] =='I') {
                cout << num << ' ';
                ans++;
                break;
            }
        }

        num++;
    }

    if (!ans) cout << "HE GOT AWAY!";
    return 0;
}
