#include "bits/stdc++.h"

using namespace std;
using LL = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string str;
        getline(cin, str);

        string cryp;
        cin >> cryp;
        cin.ignore();

        for (auto& i : str) {
            if (i == ' ') cout << i;
            else {
                cout << cryp[i - 'A'];
            }
        }

        cout << '\n';
    }
    return 0;
}