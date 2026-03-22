#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    set<string> base{"Never gonna give you up", "Never gonna let you down", "Never gonna run around and desert you", "Never gonna make you cry", "Never gonna say goodbye", "Never gonna tell a lie and hurt you", "Never gonna stop"};

    int n;
    cin >> n;
    cin.ignore();


    int i;
    for (i = 0; i < n; i++) {
        string str;
        getline(cin, str);

        if (base.count(str) == 0) break;
    }

    if (i == n) cout << "No";
    else cout << "Yes";
    
    return 0;
}
