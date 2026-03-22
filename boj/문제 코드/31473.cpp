#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a = 0, b = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        a += t;
    }
    
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        b += t;
    }

    cout << b << ' ' << a;

    return 0;
}

/*
1 ~ 1000000 까지의 값만 고려


xa - yb

- 같이 x, y가 늘어나면 차만 커질 뿐이야
-> 커지다가 뺐을 때 0이되는 경우가 있나.

gcd????

*/