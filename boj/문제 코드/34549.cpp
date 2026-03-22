#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    
    if (n == 2) n = 4;
    while ((n-1) * n / 2 % 2) n++;

    deque<int> dq;
    for (int i = 2; i <= n; i++) dq.push_back(i);

    vector<int> ans{1};

    int i = 0;
    while (dq.size() > 1) {
        if (i % 2) {
            ans.push_back(dq.front());
            dq.pop_front();
            ans.push_back(dq.front());
            dq.pop_front();
        }
        else {
            ans.push_back(dq.back());
            dq.pop_back();
            ans.push_back(dq.back());
            dq.pop_back();
        }

        i++;
    }

    if (!dq.empty()) ans.push_back(dq.front());

    for (auto& i : ans) {
        cout << i << ' ';
    }

    return 0;
}

/*
i보다 뒤에 있는 원소중에 a[i]보다 작은 값의 개수는 d[i], 큰 건 u[i]

d의 합과 u의 합이 같은 a는?
1~m까지의 숫자가 1번씩은 등장.
|a| <= 2m


일단 길이는 무조건 짝수로 만들어버려.

1 4 2 3

d 0 2 0 0
u 3 0 1 0
큰 작 큰 작 으로 하면 안되나?
안 되나 봄ㅇㅇ

----

큰 작 큰 작 느낌은 맞는 것 같은데

d가 커지게 하고
u가 커지게하고
u가 커지게하고
d가 커지게 하고

이런 느낌으로 하면?

더해지는 값이 1씩 줄어드니깐 될 것 같은데.

1 5 4 2 3
d 0 3 2 0
u 4 0 0 1

m이 4부터 성립하는 것같은데?
m == 1이면 그냥 1

m == 2
1 2 1

m == 3
1 3 2

3부터 되네.


전부 그냥 m이 최대일때 출력해버리면 되는 거 아니냐
아니네 2m이하지

6 3 2
5 4 1

7 4 3
6 5 2 1

짝수에서는 잘 되는 것 같은데?
8 7 4 3
9 6 5 2 1

아닌가?

1 2 3 4

1 2 3
1 2
3

1 2 3 4 5
합을 똑같이 나눠지지 않는 놈들도 있네.

n*(n+1)/2
를 했을 때 홀수면 안 되겠네.
그럴 때만 +1?


*/