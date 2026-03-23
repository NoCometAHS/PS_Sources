#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    cin >> a >> b;

    int aSt = -1, bSt = -1;
    for (int i = 0; i < a.length(); i++) {
        for (int k = 0; k < b.length(); k++) {
            if (a[i] == b[k]) {
                aSt = i;
                bSt = k;
                break;
            }
        }

        if (aSt != -1) break;

    }

    vector<vector<char>> ans(b.length(), vector<char>(a.length(), '.'));

    for (int i = 0; i < a.length(); i++) {
        ans[bSt][i] = a[i];
    }

    for (int i = 0; i < b.length(); i++) {
        ans[i][aSt] = b[i];
    }

    for (auto& v : ans) {
        for (auto& i : v) cout << i;
        cout << '\n';
    }


    return 0;
}