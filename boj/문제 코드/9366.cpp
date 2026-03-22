#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    int t = 1;
    while (tc--) {
        cout << "Case #" << t++ << ": ";

        vector<int> arr(3);
        for (auto& i : arr) cin >> i;

        sort(arr.begin(), arr.end());

        if (arr[0] == arr[1] && arr[1] == arr[2]) {
            cout << "equilateral\n";
        }
        else if (arr[0] == arr[1] || arr[1] == arr[2]) {
            if (arr[0] + arr[1] > arr[2]) cout << "isosceles\n";
            else cout << "invalid!\n";

        }
        else {
            if (arr[0] + arr[1] > arr[2]) cout << "scalene\n";
            else cout << "invalid!\n";
        }

    }
    return 0;
}
