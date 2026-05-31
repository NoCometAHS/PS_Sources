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

    while (tc--) {
        vector<LL> arr(6);
        for (auto& i : arr) cin >> i;

        LL PointDist = (arr[0] - arr[3])*(arr[0] - arr[3]) + (arr[1] - arr[4])*(arr[1] - arr[4]);
        LL RDist = (arr[2] + arr[5])*(arr[2] + arr[5]);



        if (PointDist <= RDist && PointDist >= pow(max(arr[2], arr[5])- min(arr[2], arr[5]),2) ) cout << "Yes\n";
        else cout << "No\n";

    }
    return 0;
}