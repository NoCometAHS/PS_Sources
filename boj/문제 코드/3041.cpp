#include "bits/stdc++.h"

using namespace std;

int main() {

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            char ch;
            cin >> ch;

            if (ch == '.') continue;
            
            int num = ch - 'A';
            int x = num % 4, y = num / 4;

            ans += abs(x - k) + abs(y - i);
        }
    }

    cout << ans;
    return 0;
}