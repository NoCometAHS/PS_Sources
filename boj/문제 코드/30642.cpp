#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, cur;
    string str;

    cin >> n >> str >> cur;

    if (str == "annyong") {
        if (cur % 2) cout << cur;
        else {
            if (cur == n) cout << cur-1;
            else cout << cur+1;
        }
    }
    else {
        if (cur % 2 == 0) cout << cur;
        else {
            if (cur == n) cout << cur-1;
            else cout << cur+1;
        }
    }

    return 0;
}
