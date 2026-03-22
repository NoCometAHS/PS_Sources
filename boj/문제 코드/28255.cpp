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

        string prefix;
        int len = (str.length() + 2) / 3;
        for (int i = 0; i < len; i++) prefix += str[i];
        
        string revPrefix = prefix;
        reverse(revPrefix.begin(), revPrefix.end());

        string tailPrefix = prefix;
        tailPrefix.erase(tailPrefix.begin());
        
        string tailRevPrefix = revPrefix;
        tailRevPrefix.erase(tailRevPrefix.begin());


        bool ans = false;
        ans |= (str == prefix + revPrefix + prefix); 
        ans |= (str == prefix + tailRevPrefix + prefix); 
        ans |= (str == prefix + revPrefix + tailPrefix); 
        ans |= (str == prefix + tailRevPrefix + tailPrefix); 

        cout << ans << '\n';
    }
    return 0;
}
