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
        int n, a, b;
        cin >> n >> a >> b;

        if (a <= b) {
            if ((n - b)%2) cout << "NO\n";
            else cout << "YES\n";
        }
        else {
            if ((n - a)%2 || (a - b)%2) cout << "NO\n";
            else cout << "YES\n";
        }
        
    }
    return 0;
}

/*
n개의 cell로 이루어진 배열.

x 선택해서 연속한 a게 cell 빨강.

y 선택해서 연속한 b개 cell 파랑.

대칭으로 만들 수 있는 x,  y가 존재하느냐.

-----------

둘 다 끝에 칠하거나, 가운대 칠하는 방법밖에 없어.

둘 다 양 끝에 칠하려면, a == b 그리고 n >= a + b을 만족해야함.

----
일단 파랑이 크거나 같으면, n - b가 짝수면 가능.


a가 더 큰 경우에는?
n - a가 짝수고, a - b가 짝수면 됨.

*/