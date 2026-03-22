#include "bits/stdc++.h"

using namespace std;

int main() {
    string s, str;

    cin >> s;
    while (s != "#") {
        cin.ignore();
        getline(cin, str);

        int ans = 0;
        for (auto& ch : str) {
            if ('A' <= ch && ch <= 'Z') ch += 32;

            ans += ch == s[0];
        }
        
        cout << s << " "<<  ans << '\n';


        cin >> s;
    }

    return 0;
}