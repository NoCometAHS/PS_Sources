#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string str;
    cin >> n >> str;

    int cnt = n+1;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'L') {
            cnt--;
            i++;
        }
    }

    cout << min(cnt, n);
    return 0;
}