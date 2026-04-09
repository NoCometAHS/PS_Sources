#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x, y, z;
    cin >> x >> y >> z;

    int arr[3];
    arr[0] = min({x,y,z}), arr[2] = max({x,y,z});
    arr[1] = x+y+z - arr[0] - arr[2];

    string order;
    cin >> order;
    cout << arr[order[0] - 'A'] << ' ' << arr[order[1] - 'A'] << ' ' << arr[order[2] - 'A'];
    return 0;
}