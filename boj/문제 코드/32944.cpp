#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;

    if (n == m) {
        cout << -1;
        return 0;
    }


    int cur = 1;
    for (int i = 0; i < k - 1; i++) {
        cout << cur++ << ' ';
    }

    for (int i = 0; i < n - m; i++) {
        cout << n - i << ' ';
    }
    
    for (int i = 0; i < m - (k-1); i++) {
        cout << cur++ << ' ';
    }
    
    return 0;
}

// 1 ~ n 한번씩 쓰면서
// lis 길이가 m이면서, 잘못된 알고리즘으로는 k를 뱉는 수열 찾기. 없으면 -1
/*
잘못된 알고리즘.
처음부터 하나도 안 버리고 커지는 수열

- k와 m은 무조건 다르고, k가 더 작다.
- m은 n과 같을 수 있음.

LIS 값은 유지하는데, 잘못된 알고리즘만 크기를 줄일 수 있나
1, 2, 3, 4, 5

가장 큰 숫자를 사이에 박아 넣는게 가장 쉬운 것 같은데,

1, 5, 2, 3, 4
같이.


- m == n인 경우에는 무조건 불가능하다. 오름차순이 유일한데, k를 만드려면 오름차순 포기해야함. 이 경우만 불가능 같은데

m = 5
k = 2
n, n-1,... 1 2 3 4 5
-> n-1,... 1 n 2 3 4 5

이런 느낌이고 싶은데 걘 n-1을 넣겠구나

숫자가 개많다면
정현이 수열, 그 수열보단 작지만 lis 구성할 얘보단 큰 값, 1 2 3 4 5


1 2 3 4 5 ... n
m = 5
k = 2

1 5 2 3 4 n ... 6
이렇게 하면 무조건 되는 것 같은데.

1 2 n .. 3

2 1 n ... 3
이렇게 바꾸면
무조건 m이 k보단 하나 이상 더 크고
k를 확정지을 수 있으니깐

아냐 k도 1 증가하잖아.

1 n 2 3 4 n-1 ... 5
가 되어야 하나.

그럴듯.

1 n n-1 ....6 1 2 3 4 5
ㄱㄱ
*/