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
 
        if (n <= 3) {
            cout << n ;
        }
        else if (n % 2 == 0) {
            cout << 0;
        }
        else {
            cout << 1;
        }
 
        
        cout << '\n';
    }
    return 0;
}
/*
3 * 2
3 * 4
3 * 6
 
2, 3명씩 묶을 거고
팀은 2가지 중 하나 선택
 
2가지에 있는 사람들의 차중 가장 작은 거.
 
 
2명씩 묶을 때,
팀이 홀수라면, 3명씩 묶을 수 있는 지 봐
 
2 * 3
2 * 5
2 * 7
 
10
2 3 2 3
7 = 2 2 3
2 와 3의 합으로 2 이상의 자연수를 만들 수 있어.
그러니깐 2로 묶을 수 있으면 0
2제외 하고
 
2명씩 묶는데 사람이 남아.
 
3
3 
5
3 2
7
2 2 3
9
2 2 3 2
11
2 3 3 3
3빼면 다 1씩 차이 나나
 
 
 
*/