#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<string> arr(10101);
    for (int i = 0; i < 5; i++) {
        string str;
        cin >> str;

        for (int k = str.length() - 1; k >= 0; k--) {
            arr[k].push_back(str.back());
            str.pop_back();
        }
    }

    for (int i = 0; arr[i].size() != 0; i++) {
        if (arr[i][1] == '.') continue;

        if (arr[i][0] == '.') {
            arr[i][2] = 'w';
            arr[i].erase(arr[i].begin());
            arr[i].push_back('.');
        }
        else {
            arr[i][1] = 'm';
            arr[i].pop_back();
            arr[i].insert(arr[i].begin(), '.');
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int k = 0; arr[k].size() != 0; k++) {
            cout << arr[k][i];
        }
        cout << '\n';
    }
    return 0;
}
