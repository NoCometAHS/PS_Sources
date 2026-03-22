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
        int n;
        cin >> n;

        TwoVector<int> arr(3, vector<int>(n));

        for (auto& v : arr) {
            for (auto& i : v) cin >> i;
        }
        

        LL ab = 0, bc= 0;
        for (int i = 0; i < n; i++) {
            bool f = true;
            for (int k = 0; k < n; k++) {
                if (arr[0][k] < arr[1][(k + i) % n]) continue;

                f = false;
                break;
            }

            if (f) {
                ab++;
            }

            f = true;
            for (int k = 0; k < n; k++) {
                if (arr[2][k] > arr[1][(k + i) % n]) continue;

                f = false;
                break;
            }

            if (f) {
                bc++;
            }
        }

        cout << ab * bc * n << '\n';
    }
    return 0;
}

/*
눈사람
머리, 몸, 다리
크기를 각각 a b c

a < b < c 만족

n개의 눈덩이로 이루어진 3개의 원형으로 도는 컨베이어. 

각 컨베이어의 시작으로부터 인덱스 i j k

i, j, k를 시작으로 1씩 더해가먄서 해당 눈덩이로 눈사람 쭉 만들어 감.

만족하는 모든 조합의 개수.

---
브포로는 안 되겠네
5000^3

행렬로 봤을 때, 행끼리 쉬프트 연산을 하고(일관성 있게 오른쪽 쉬프트라고 생각하자)

모든 열에서 아래로 갈 수록 커지기만 하는 경우를 구해야 함.


---
연산은 해봤자 쉬프트 연산

-> 어떤 맞는 경우가 있을 때, 3개 동시에 옮기면 똑같이 맞음.

어떤 맞는 경우가 있다고 했을때, 어떤 행에 쉬프트를 하고도 맞는 경우가 되려면?

중간은 보기 어려우니깐 위, 아래만 돌려볼까?
-> 이거만 봐도 다 찾은 거 아냐? 이 결과 값에, n만 곱하면 되는 거 아닌가?

1 1 1 
2 2 2
3 3 3

위 아래 동시에 돌리는데 5000^2, 돌려도 되는 지 확인 하는데 5000;
시간 초과 인데..

---
돌려도 되는 지 확인을 빠르게 할 수 있을까?
열끼리 오름차순인지 확인 해야해

---
더 덜 돌려볼 수 있을까?


1, 2 번끼리 맞는 거 찾고
2, 3 번끼리 맞는 거 찾고

같은 2번인 것들의 합은?

찾았을 때 n씩 더해줘야 하나?

좋은데?
*/