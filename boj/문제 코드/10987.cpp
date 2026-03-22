#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    char ch;

    int ans = 0;
    while ((ch = getchar()) != '\n') {
        ans += (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');
    }

    cout << ans;
    
    return 0;
}
