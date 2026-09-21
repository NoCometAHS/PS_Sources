#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        string str;
        cin >> str;

        str.erase(str.begin()+1);
       
        for (int i = str.length()- 1; i >= 1; i--) {
            if (str[i] > '4') str[i-1]++;
        }

        if (str[0] == '1') cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}