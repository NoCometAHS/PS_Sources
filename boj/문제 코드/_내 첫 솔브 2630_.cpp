#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

void func(int x, int y, int l, TwoVector<int>& arr, int& blue, int& white) {
    if (l == 1) {
        if (arr[y][x]) blue++;
        else white++;

        return;
    }

    int c = 0;
    for (int i = 0; i < l; i++) {
        for (int k = 0; k < l; k++) {
            c += arr[y + i][x + k];
        }
    }

    int ll = l /2;
    if (c == 0 || c == l*l)  {
        func(x,y,1, arr, blue, white);
    }
    else {
        func(x, y, ll, arr, blue, white);
        func(x+ll, y, ll, arr, blue, white);
        func(x, y+ll, ll, arr, blue, white);
        func(x+ll, y+ll, ll, arr, blue, white);
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    TwoVector<int> arr(n, vector<int>(n));
    for (auto& v : arr) for (auto& i : v) cin >> i;

    int blue = 0, white = 0;
    func(0, 0, n, arr, blue, white);

    cout << white << '\n' << blue;

    return 0;
}
