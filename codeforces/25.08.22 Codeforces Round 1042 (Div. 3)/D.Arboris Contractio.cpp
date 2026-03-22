#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;

        int mx = -1;
        vector<int> cnt(n+1, -1);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            
            cnt[u]++;
            cnt[v]++;

            mx =  max({cnt[u], cnt[v], mx});
        }
cout << "----\n";
        int sum = 1;
        for (auto& i: cnt) {
            cout << i << ' ';
            sum += i;
        }

        cout << sum - mx << '\n';
    }
    return 0;
}

//not submit
/*
나무 얻어야함. -> 그 트리였음 ㅋㅋ;;

지름에 비용이 달렸음.

첫번재로 지름 최대한 줄일거임. 다음연산을 통해.

1.두정점 s, t 선택. s를 시작, t를 끝으로 하는 단순 경로.
2. 그 경로의 모든 간선 제거.
3. 모든 정점 s에 연결.

최소의 지름을 얻기 위한 최소의 연산 횟수는?

--------------
무조건 최소 지름은 1이야. -> 한 정점에 모든 정점이 붙어 있어야함.

나 자신한테 안 붙어 있으면 무조건 연산을 해야하나? ㅇㅇ. 경로에 있든가 해서 최소 한 번씩은 당해야함.

-----------
정점 s를 하나로 고정해야하나? ㅇㅇ -> 다른 거 하고 또 하면 처음에 했던 애에 붙어 있는 거 다 다시 해야함.

어떤 걸 s로 정해야하나?

임의의 정점을 s로 잡았을 때 연산 횟수는
모든 자식들의 (자식의 수-1)의 합.

어떤 정점이 위에있으나 아래에 있으나 (자식의 수 -1)은 같잖아. 

(자식의 수 -1)을 다 구하고, 가장 큰 수를 뺀 합이 정답 아니냐.
-> 가장 큰 수를 빼면 안 되는게, 자식의 자식이 있으면 갠 연산을 한다고 봐야 하잖아.
이제 자식의 자식을 봐야 한다면> 위, 아래가 의미 있어지니깐 이 방법으로는 무리같아.

---------
*/