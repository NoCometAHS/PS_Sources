#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w;
    cin >> h >> w;


    vector<vector<int>> arr(h, vector<int>(w));

    for (int i = 0; i < h; i++) {
        for (int k = 0; k < w; k++) {
            char ch;
            cin >> ch;
            arr[i][k] = ch == '#';
        }
    }


    vector<iipair> dir{{1,0}, {1,-1}, {0,-1} , {-1,-1}, {-1,0}, {-1,1}, {0,1} , {-1,1} };
    vector<vector<int>> temp(h, vector<int>(w));
    for (int t = 0; t < 10; t++) {
        for (int i = 0; i < h; i++) {
            for (int k = 0; k < w; k++) {
                int t = arr[i][k];
                
                temp[i][k] = 0;
                
                if (t) continue;

                for (auto& [dy, dx] : dir) {
                    auto [nx, ny] = tuple(k + dx, i + dy);
                    if (ny < 0 or ny >= h or nx < 0 or nx >= w) continue;

                    if (!arr[ny][nx]) continue;
                    temp[i][k] = 1;
                    break;
                }
            }
        }

        swap(arr, temp);
    }


    for (auto& v : arr) {
        for (auto& i : v) cout << (i == 1 ? "#" : ".");
        cout << '\n';
    }

    

    return 0;
}

/*
오직 최소한 하나의 검정색 칸이 인접해 있을 때, 흰색이였던 칸이 검어져. (인접하다는 건 주위 8칸을 의미함)
검은색이였으면 흰색이 됨.

이걸 10^100 번 반복.


그냥 반복되나?
뭔가 반복되는 지점이 있으니깐 한 것 같은데.

반복되는 지점을 어떻게 찾느냐가 중요한 지점이야.


배열의 상태를 set, map으로 기록할 수가 없어.

---

일단 한 번 검정이 됐으면, 
다음 그로부터 2번 연산이 진행 될 때 다시 돌아옴 무조건.


그러면, 언젠가 부터는
2가지 형상만 반복하는 거 아니냐?

다 하애진 것 빼고

---

대충 돌리고 나서 보면 될 줄 알았는데,
그렇게 많이 돌릴 수도 없었네.

1 x 10^6
같은 경우에는

최소한 10^6 번은 돌려봐야 한다.

뭔가 max(h, w)번은 최소 돌려야 할 거고.
 
그러면? max(h, w)번 했을 때의 연산 결과만 가지고 있으면 된다는 건데! (홀수라면 그 다음번거까지)


한 줄씩 보기는 에바.

어떤 한 칸에 대해서만, 임의의 연산 횟수에 대해 색을 알 수 있나?

일단
내가 검정
    - 주위 1칸이라도 흰색 있으면, 짝수 번째에 검정
    - 전부 검정이다, 확인을 해봐야 함.
        -> 거리가 홀수인 곳에 흰색이 있다. 짝수번째에 검정이 됨.
        -> 거리가 짝수인 곳에 흰색이 있다. 홀수번째에 검정이됨 -> 답에선 하양
내가 하양
    - 1칸이라도 검정이면, 홀수 번째에 검정 -> 답에선 하양
    - 전부 하양이다, 확인을 해봐야함. -
        -> 거리가 홀수인 곳에 검정이 있다. 홀수번째에 검정이 됨. -> 답에선 하양
        -> 거리가 짝수인 곳에 검정이 있다. 짝수번째에 검정이됨 

가장 가까운 검정
가장 가까운 하양
이 어딨는 지 알아야 해.

진짜 각 방향대로 8번 돌려서 찾고 해야 하나?
근데 시간 없노 ㅋㅋ.
*/