#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    if (n - 1023 <= 0) cout << "No thanks";
    else if ((n - 1023) & ~m) cout << "Impossible";
    else cout << "Thanks";
    return 0;
}

// 1023원 이하면 알아서 다 살 수 있어.
