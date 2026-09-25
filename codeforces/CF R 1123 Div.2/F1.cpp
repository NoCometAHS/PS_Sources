#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL tc;
    cin >> tc;

    while (tc--) {
        LL n, q;
        cin >> n >> q;

        vector<LL> arr(n);
        for (auto& i : arr) cin >> i;
        sort(arr.begin(), arr.end());

        vector<LL> dp({arr.back() - arr.front()});
        while (true) {
            vector<LL> temp;
            for (int i = 0; i < n; i++) {
                for (int k = i+1; k < n; k++) {
                    temp.push_back(arr[i] ^ arr[k]);
                }
            }

            sort(temp.begin(), temp.end());


            for (int i = 0; i < n; i++) {
                arr[i] = temp[i];
            }

            dp.push_back(arr.back() - arr.front());

            bool flag = true;
            for (int i = 0; i < n; i++) {
                flag &= arr[i] == 0;
            }

            if (flag) break;
        }

        while (q--) {
            LL x;
            cin >> x;

            cout << (x >= dp.size() ? 0 : dp[x]) << '\n';
        }
    }

    return 0;
}

/*
m개의 원소를 가진 배열 b에 대해서 transformation를 다음과 같이 정의한다.
모든 1 <= i < j <= m에 대해서, b[i] xor b[j]를 한 값을 적는다.
적은 값 중 가장 작은 m개를 가져간다.
그 수로 b를 적는다.

음이아닌 정수로 이루어진 a.
max(a)는 a의 최대값, min(a)는 a의 최소값

x번의 transformation 한 후의 max(a) - min(a)값을 구하라.
각 쿼리는 독립적.

작은 값 n개만 빠르게 알아내면 그냥 반복문 해서 하면 됨. ㄴㄴㄴㄴ x가 2^30까지였네.


답이 0되는 임계치가 있음. 
*/