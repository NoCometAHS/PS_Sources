#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int gcd(int a, int b) {
    if (b) return gcd(b, a % b);
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> arr(6);
    for (auto& i : arr) cin >> i;

    int a = gcd(arr[4], arr[5]);
    arr[4] /= a, arr[5] /= a;

    int mn = 1e9, ansX, ansY;
    for (int i = 0; i <= 100; i += 1) {
        int dist = pow<int>(arr[2] - arr[0], 2)  + pow<int>(arr[3] - arr[1], 2);

        if (dist < mn) {
            mn = dist;
            ansX = arr[2];
            ansY = arr[3];
        }

        arr[2] += arr[4];
        arr[3] += arr[5];
    }

    cout << ansX << ' ' << ansY;

    return 0;
}
