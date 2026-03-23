#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<string> arr(n);
    for (auto& s :arr) cin >> s;

    int cur = 0;
    while (arr[cur] != "KBS1") {
        cur++;
        cout << 1;
    }

    while (cur) {
        swap(arr[cur], arr[cur-1]);
        cout << 4;
        cur--;
    }
    
    while (arr[cur] != "KBS2") {
        cur++;
        cout << 1;
    }

    while (cur > 1) {
        cur--;
        cout << 4;
    }

    return 0;
}