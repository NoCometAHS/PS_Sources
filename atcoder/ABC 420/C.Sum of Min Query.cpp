#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;

    vector<LL> A(n), B(n);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    LL sum = 0;
    for (int i = 0; i < n; i++) {
        sum += min(A[i], B[i]);
    }

    while (q--) {
        char ch;
        int x, v;
        cin >> ch >> x >> v;
        x--;

        sum -= min(A[x], B[x]);
        
        if (ch == 'A') {
            A[x] = v;    
        }
        else {
            B[x] = v;
        }

        sum += min(A[x], B[x]);
        cout << sum << '\n';
    }
    return 0;
}

/*
길이가 n인 정수열 A, B.

순서대로 처리해야할 Q개 쿼리.

c x v

c가 A라면
A[x]를 v로 바꿔.

c가 B라면
B[x]를 v로 바꿔.

쿼리 처리하고 계속 min(A[i], B[i])의 합을 출력해.


*/