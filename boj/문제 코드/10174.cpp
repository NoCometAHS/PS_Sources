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
    cin.ignore();

    while (tc--) {
        string str;
        getline(cin, str);
        
        bool ans = true;
        for (int lt = 0, rt = str.length() - 1; lt < rt; lt++, rt--) {
            str[lt] = tolower(str[lt]), str[rt] = tolower(str[rt]);

            if (str[lt] == str[rt]) continue;

            ans = false;
            break;
        }

        if (ans) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}
