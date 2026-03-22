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

    while (str != "#") {
        int one = 0;
        for (int i = 0; i < str.length() -1; i++) {
            one += str[i] == '1';
            cout << str[i];
        }

        
        if (str.back() == 'e') {
            if (one % 2) cout << '1';
            else cout << '0';
        } 
        else {
            if (one % 2) cout << '0';
            else cout << '1';
        }
        cout << '\n';

        cin >> str;
    }
    return 0;
}
