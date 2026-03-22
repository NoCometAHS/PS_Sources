#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string str;
    cin >> n >> str;


    cout << str[0];
    for (int i = 1; i < n; i++) {
        cout << str[i];
        if (str[i-1] == 'P' && str[i] == 'S') {
            int j = i + 1;

            while (j < n && (str[j] == '5' || str[j] == '4')) {
                j++;
            }
            i = j-1;
        }
    }
    return 0;
}
