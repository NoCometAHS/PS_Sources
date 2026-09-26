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

        
    }
    return 0;
}

/*
일단 모든 a_i + b_i = p_i에서 생각해.
1. sum(p) > x + y
무조건 불가능

2. sum(p) <= x + y
마지막에 남는 거 전부 짬리 하면 됨.


p_i 가 홀수면
    p_i//2, p_i//2 + 1
    로 나누기만 하면 됨

P_i가 짝수면
    p_i//2 - 2, p_i//2 + 2
    로 나눠야 해

    **제정신 아니였네 ㅋㅋ; 1씩 차이나지 왜 이래.**

s_i와 p_i를 돌면 불균형의 개수가 얼마나 나는 지 알 수 있어.
기본적으로 어디에 몇개 더 줘야 하는 지 알 수 있어.
d 라고 하자 (양수면 a에 더 주기, 음수면 b에 더 주기)

x - y (x > y)를 z라고 할 때.

z와 d의 관계를 보면?
z == d 여야지 할 수 있는 거 아닌가?
일단 부호가 틀리면 못 만들어.

흠;;; 아닌 것 같기도 하고.





*/