#include "bits/stdc++.h"

using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        string toSay;
        cin >> toSay;

        int n;
        cin >> n;

        string ans;
        int dif = 1e9;
        while (n--) {
            string word;
            cin >> word;

            int t = 0;
            for (int i = 0; i < toSay.length(); i++) {
                t += toSay[i] != word[i];
            }

            if (dif > t) {
                dif = t;
                ans = word;
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}