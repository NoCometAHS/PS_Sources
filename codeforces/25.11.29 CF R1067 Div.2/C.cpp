#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

LL func(vector<LL>& arr) {
    LL sum = 0, ans = -2e9;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        int n, turn;
        cin >> n >> turn;

        vector<LL> a(n), b(n);
        for (auto& i : a) cin >> i;
        for (auto& i : b) cin >> i;
        
        if (turn % 2) {
            LL mx = -2e9, mxIndex;
            for (int i = 0; i < n; i++) {
                LL inc = (a[i] < 0 ? a[i] : 0) + b[i];
                if (mx < inc) {
                    mx = inc;
                    mxIndex = i;
                }
            }

            a[mxIndex] += b[mxIndex];
        }
        cout << func(a) << '\n';

    }

    return 0;
}

/*
길이가 n인 배열 a, b
총 턴 k

Alice 먼저 bob 다음

인덱스 고르고 다음 연산 진행
add ai += bi
subtract ai -= bi

최대 비지 않은 부분 배열의 합이 점수. 앨리스는 점수 최대화.

최종 점수는?


bob은 가장 큰 수만 계속 빼고 있으면 되는 거 아냐?

턴이 홀수면 가장 큰거 더하고 연산.
턴이 짝수면 그냥 구하고.

연결하는 수를 더하는 게 이득일 수가 있나?

5 1
3000 -3001 10000 10000 10000
1 4002 4002 1 1


*/