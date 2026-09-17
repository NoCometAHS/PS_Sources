#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}

/*
c는 일단 없다고 해보자.

b보다 a의 개수가 더 많은 연속한 부분 문자열 개수

일단 무슨 문자열을 세야 할까.
    길이가 1인 부분 문자열
    a의 개수

    길이가 2인 부분 문자열
    aa의 개수

    길이가 3인 부분 문자열
    aaa, aab, aba, baa의 개수

    길이가 4인 부분 문자열
    aaaa, aaab, aaba, abaa, baaa

    길이가 5인 부분 문자열
    aaaaa, aaaab, aaaba, aabaa, abaaa, baaaa,
    aaabb, aabab, abaab, baaab, aabba, ababa,
    baaba, abbaa, babaa, bbaaa

연속한 문자열을 숫자로 나타냈을때?

b를 기준으로 생각해서 왼쪽 오른쪽 보기?
    b는 최대 1개만 연속할수 있다면?


지금 한 지점에서 왼쪽 오른쪽 보는 것에 집중하고 있는데,
다르게 구할 수는 없나?  
    왼쪽에서 시작해서 하나씩 문자를 더해가. --> 1
        그러면 b가 추가 될 때마다 고정되는 부분이 생겨 그거 감안해서 가능한 경우 더하기?
        반대쪽에서 동일하게 한 번 더.

        b와 b사이를 움직일때 경우의 수 계산하는 게 힘들어지는 것 같은데.
        b있는 곳마다 dp?

...b...b
가 있고 처음 ...을 x 두번째 ...을 y라고 하자

두번째 b와 y전부를 선택한 경우의 수를 알아
흠, b와 b 사이는 전부 포함 되겠네.

a를 중요하게 봐보자.
연속한 a에 대해서는 경우의 수 잘 셀수 있어.

끝에 b를 붙인다면?


일단 연속한 a에 대해서 모든 경우의 수를 다 더해놔
    그럼 b를 붙이는 경우에 대해서만 생각할 수 있어.
    그랬을 때 1번방법을 써서 구하면 되는 거 아닌가.
        각각의 연속b들에 대해서 봐주고 합쳐서 봐주고 해야 해서 ㅂㄱㄴ.

b를 -1
a를 1이라고 바꾸고

구간 합이 양수면 되잖아.
그런 느낌?


*/
