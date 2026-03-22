#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a = 0, b = 0;
    char recentWin = 'D';

    vector<int> arr1(10), arr2(10);
    for (auto& i : arr1) cin >> i;
    for (auto& i : arr2) cin >> i;

    for (int i = 0; i < 10; i++) {
        if (arr1[i] < arr2[i]) {
            b += 3;
            recentWin = 'B';
        }
        else if (arr1[i] > arr2[i]) {
            a += 3;
            recentWin = 'A';
        }
        else {
            a += 1;
            b += 1;
        }
    }

    cout << a << ' ' << b << '\n';

    if (a < b) {
        cout << 'B';
    }
    else if (a > b){
        cout << 'A';
    }
    else {
        cout << recentWin;
    }

    
    return 0;
}
