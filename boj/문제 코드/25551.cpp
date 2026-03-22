#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int arr[3][2];
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    int one = min({arr[0][0], arr[1][1], arr[2][0]}), other = min({arr[0][1], arr[1][0], arr[2][1]});
    int t = min(one, other);
    one -= t, other -= t;
    cout << t * 2 + (one != 0) + (other != 0);

    return 0;
}

/*

입을 수 있는 세트 수가 나오네.

그 세트 수 더해서 홀수 나오는 수중 가장 큰 거.

*/