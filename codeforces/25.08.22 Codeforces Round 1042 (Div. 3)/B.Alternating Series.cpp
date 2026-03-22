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

        for (int i = 0; i < n; i++) {
            if (i % 2) {
                if (i == n-1) cout << 2;
                else cout << 3 << ' ';
            }
            else cout << -1 << ' ';
        }
        
        cout << '\n';
    }
    return 0;
}
//accepted
/*
인접한 원소의 곱이 음수.
길이가 2 이상인 모든 서브 어레이마다 각 원소의 합이 양수.
-> 좋은 배열.

모든 원소에 절대값 씌웠을 때 사전적으로 더 작은게 좋다.

길이 n이 주어졌을 때, 최고로 좋은 배열 찾아라.

---------
맨 앞에 음수를 넣어야 사전적으로 작음. 
-> ㄴㄴㄴㄴ 절대값이 작아야 함으로 -1 넣어야함.
    전체적으로 숫자가 작야하니깐 음수들은 -1을 넣어야함. 더 큰 수 넣으면 양수부가 어디선가는 커져야함.
    맨 앞이 양수가 될 수는 없어. 1을 넣을 수가 없기 때문에.
    양수가 커봐야 3이상은 안 갈 것 같은데? 양 옆 음수 다음에 무조건 양수가 나오니깐.

    끝이 양수면 2여도 충분함

인접한 원소의 곱이 음수여야하니깐 발로 다음에 양수, 또 다음 음수...

-----------
모든 서브 어레이마다 원소의 합이 양수?

모든 원소의 합이 일단 양수.
*/