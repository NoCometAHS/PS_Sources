#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    vector<int> prefixSum(n+1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i+1] = prefixSum[i] + arr[i];
    }

    while (q--) {
        int qry;
        cin >> qry;

        if (qry == 1) {
            int x;
            cin >> x;

            prefixSum[x] += arr[x];
            prefixSum[x+1] -= arr[x-1];

            swap(arr[x-1], arr[x]);
            swap(prefixSum[x], prefixSum[x+1]);
        } 
        else {
            int l, r;
            cin >> l >> r;

            cout << prefixSum[r] - prefixSum[l-1] << '\n';
        }
    }
    return 0;
}

// 1 seg tree
// 2 sqrt decomp
// 그 누적합 응용 뭐 있지 않나. 그 차이를 저장하는 뭐 그런거였던 것 같네. 근데 그건 ㄱㅊ.
// 그냥 누적합으로 되는 거 아닌가 ㄴㄴ 스왑한 그 사이의 값들 전부 업데이트 해 줘야 하는데 l, r이 
// ㄴㄴㄴ x, x+1만 바꾸네? 그럼 그냥 누적합