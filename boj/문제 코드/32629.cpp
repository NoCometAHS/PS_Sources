#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        LL n;
        cin >> n;

        LL a = sqrt(n), b = sqrt(n);
        while (a*b < n) {
            a++;
            
            if (a*b >= n) break;
            
            b++;
        }

        cout << a * 2 + b * 2 << '\n';
    }
    return 0;
}

// 변을 더 줄일 수 없게 하고 블록을 다 넣을 수만 있으면 정답인데?
