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

    for (int i = 0; i < n + 2; i++) cout << "@";
    for (int i = 0; i < n; i++) {
        cout << "\n@";
        
        for (int k = 0; k < n; k++) cout << " ";
        cout << "@";
    }

    cout << "\n";
    for (int i = 0; i < n + 2; i++) cout << "@";
    return 0;
}
