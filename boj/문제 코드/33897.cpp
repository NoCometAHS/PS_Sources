#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int mxLen = 0, count = 1, pre = -1, curLen = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (pre <= num) {
            curLen++;
            mxLen = max(mxLen, curLen);
        }
        else {
            count++;
            curLen = 1;
        }

        pre = num;

        
    }

    

    cout << count << ' ' << mxLen;
    
    return 0;
}
