#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    string str;
    cin >> str;

    int count = 1;
    for (int i = 0; i < n-1 && count < 5; i++) {
        count++;
        if (abs(str[i] - str[i+1]) != 1) {
            count = 1;
        }
    }

    if (count < 5) cout << "NO";
    else cout << "YES";

    return 0;
}
