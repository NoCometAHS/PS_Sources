#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL x, n;
    cin >> x >> n;


    unordered_map<LL, int> order;
    vector<LL> numbers;

    int idx = 0;
    while (n--) {
        if (x & 1) {
            x = x << 1 ^ 6;
        }
        else {
            x = x >> 1 ^ 6;
        }

        if (order.count(x)) break;

        order[x] = idx++;
        numbers.push_back(x);
    }

    if (n > 0) {
        int len = idx - order[x];

        n %= len;

        x = numbers[order[x] + n];
    }

    cout << x;

    return 0;
}

// 110 = 6
/*
짝수면 오른쪽 시프트
홀수면 왼쪽 시프트

여기서 xor 하면 어떤 일이 일어나나?

1. x가 홀수였어.
...1
시프트하고 110이랑 xor하면?
...00



2. x가 짝수였어
2-1. ...10
시프트하고 110으로 xor하면?
...1 이 되네

2-2. ...00
...0이 되네

-> ...10이 나올때까지 계속 반복할거야.

-> 뭔가 계속 수가 작아지는 것 같은데.

b1100
-> b0000
-> b0110
-> b0101
-> b0100
-> b0100

뭔가 쭉 같아지는 부분이 생기나?

4가 되면, 항상 4로만 되나보네.

이런 수가 더 있나
b010 x
b001 x
b110 x
b101 x
b011 x
b111 x

4만 특별한 듯?
n이 겁나 크면 4로 하고
아니면 그냥 해볼까

쓰읍 ㅋㅋ
뭔가 더 있나보네.


---
태그에 맵, 셋이 있네.

반복되는 구간 찾긴가?
아!

111110100
이라도 계속 반복되는 거 아니냐
아니넹..

그냥 반복되는 구간 찾긴가.

---
반복되는 구간이 있어야 해.
걍 n이 음수 되서 그런거 아녔어?
*/