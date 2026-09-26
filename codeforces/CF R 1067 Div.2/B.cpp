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
        int n;
        cin >> n;

        unordered_map<int,int> numberFreq;
        for (int i = 0; i < n * 2; i++) {
            int num;
            cin >> num;

            numberFreq[num]++;
        }

        int grpCnt[3] = {0, };
        for (auto& [num, freq] : numberFreq) {
            if (freq % 2) {
                grpCnt[2]++;
            }
            else if (freq % 4 == 0) {
                grpCnt[1]++;
            }
            else {
                grpCnt[0]++;
            }
        }

        int ans = grpCnt[0] * 2 + grpCnt[1] * 2 + grpCnt[2];
        int imbalance = grpCnt[1]%2  + grpCnt[2] % 2;

        if (imbalance == 1) {
            if (grpCnt[2] != 0 && grpCnt[2] % 2 == 0 ) cout << ans;
            else cout << ans - 2;
        }
        else {
            cout << ans;
        }

        cout << '\n';
    }
    return 0;
}
 
/*
2n개의 정수 수열 a
f(b)는 부분수열 b에서 등장횟수가 홀수인 서로 다른 원소 개수
 
2개의 부분수열로 나눠서 최대값 찾기.
 
여러개인 수를 홀수개로 나눌 수 있으면 좋지.


수가 홀수개
홀, 짝으로만 나누어짐



수가 짝수개

힌트1
Does the contribution of an element depend on its exact split (u,v), or only on whether u and v are odd or even?
홀짝으로 나누어진 것만 중요하지 ㅇㅇ.
시합 때 발견했음.

힌트2
If every distinct element contributed its maximum possible amount, what would be the upper bound of the answer?
구별된 요소의 개수가 n개라면
2*n이 답의 상한일거야. (각 요소의 개수를 양분했을 때, 홀수 개라면)

힌트3
Elements with frequency of the form 4k+2 can be split as (2k+1,2k+1),
 creating 0 size imbalance. Elements with frequency of the form 4k can be split as (2k−1,2k+1)
, creating 2 size imbalance.

4k+2와 4k는 각각 불균형을 0, 2씩 만들지 ㅇㅇ.
시험때도 찾았지.

힌트4
The number of elements with odd total frequency is always even. How can these elements help correct any size imbalance?
모든 나온 횟수가 홀수인 원소 수는 항상 짝수다. 크기 불균형 해소에 어떻게 도움이 될까?

빈도가 홀수는 무조건 짝 / 홀로 나누어져. 몇개로 나누던지 상관이 없이 답을 1 늘려주네.
이런 요소가 짝수개라면? 크기 불균형에 도움이 안 되는 거 아니냐?

홀수여야 min(imbalance, odd num) 만큼 불균형도를 제거 해주지.

~~짝수여도 할 수는 있긴 한데, 홀수개 남았을 때가 문제 아니야? 오히려 불균형도가 없을때 불균형도를 증가시키는데~~
틀린듯.


홀수가 짝수개면? 4k가 있어도 완전히 완충되나?
1개씩 때다 줘가지고 할 수 있는 듯.

*****
불균형도 제거해주고 남은 값들은 서로 완충작용하기?
*****

두 홀수가 있다면 무조건 2개의 짝수로 만들수 있잖아

완충 작용하고 나서 그 수가 홀수인지... 불균형은 4k가 2씩 만드니깐 홀수지.

1 5
v
3 3


오히려 1개이면 불균형도가 증가하네.


힌트5
In which situation does the size imbalance become impossible to fix, making the upper bound unreachable?

상한 값에 도달 할수 있게 고치지 못하는 상황은 어떨때인가?

빈도가 4k인 요소가 홀수개인데, 빈도가 홀수인 얘도 홀수면, 정상인 애들 때와야함.

이때 홀수인 애들은 어떻게 나누던 답을 1씩 늘려주니깐 신경쓰지 말고

4k, 4k+2인 얘들에서 얼마나 줄어드는 지 보면 될 것같은데?

얼마나 줄어들지 어떻게 알지?
각 수에서 짝수개씩만 때다 주면 답은 안 변하지 않을까?

불균형도도 홀수야 하나?

오?
그러면 모든 수에서 짝수개씩만 떼다가 쓰고
한 수에서만 홀수개 박으면 불균형도  해결 되는 거 아니냐?

~~애초에 불균형도는 1 아니면 2아니면 3일 수 밖에 없어.~~
~~빈도 4k인 얘가 홀수 개 거나, 빈도 홀수인 애가 홀수 개거나, 둘 다 있거나.~~

4k가 홀수개이고 홀수도 홀수라면 안 변해 서로 보안해주니깐

빈도 4k 개수가 홀수거나, 빈도 홀수가 홀수개거나 둘 중 하나일 때
답에서 2씩 줄어들어

어떤 수에서 1개씩 옮겨와야 하니깐.

----------
먼저 빈도가 4k인 얘들 개수, 홀수 개수를 세자.

그럼 불균형도가 나올거야
    1
    어디 답 건드려야 하는데 1씩 옮기면 상한에서 2가 줄어들겠네
    2
    그냥 빈도 4k 요소 본인이 하면 답이 2 줄어들고,
    4k+2가 있다면 2개를 한번에 옮겨서 답이 안 줄어들고
    그 외는 다 2 줄어들어

    3
    이거 불균형도 1인 경우로 똑같은거 아니냐?
    4k의 불균형도를 홀수가 보안해 주면

    불균형도 1만 남는데 이거 해결하려면 답에서 2가 줄잔아
위에 다 틀렸고 ㅋㅋ;;


빈도가 4k+2, 4k, 홀수인 애들 중에 빈도가 가장 큰수만 가지고 있자, 그거 하나만 옮겨도 되니깐
어짜피 4k+2가 6부터라 ㄱㅊ.

수 하나 옮길때마다 불균형도 2씩 줄어들잖아 ㅋㅋ;'




*/