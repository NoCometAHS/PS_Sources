#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int GetCandidateCnt(string base, string chk) {
    LL res = 0;

    for (int i = 0; i < base.length(); i++) {
        bool f = true;

        for (int k = 0; k < chk.length(); k++) {
            int idx = i + k;

            if (idx >= base.length()) {
                f = false;
                break;
            }

            if (base[idx] == chk[k]) continue;
            else {
                if (chk[k] == '*') continue;
                else {
                    f = false;
                    break;
                }
            }
        }

        res += f;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<string> arr(4);
    for (auto& s: arr) cin >> s;


    cout << GetCandidateCnt(arr[0], arr[1]) << '\n';

    LL ans = 0;
    set<int> leftStringIdx{0,1,2,3};
    for (int upStringIdx = 0; upStringIdx < 4; upStringIdx++) {
        for (int downStringIdx = 0; downStringIdx < 4; downStringIdx++) {
            if (upStringIdx == downStringIdx) continue;

            leftStringIdx.erase(upStringIdx);
            leftStringIdx.erase(downStringIdx);

            string upString = arr[upStringIdx];
            string downString = arr[downStringIdx];

            int minLenght = min(upString.length(), downString.length());
            
            for (int dist = 1; dist <= 15; dist++) {

                for (int firstStringPos = 0; firstStringPos <= minLenght; firstStringPos++) {
                    for (int secondStringPos = 0; secondStringPos <= minLenght; secondStringPos++) {
                        if(abs(firstStringPos - secondStringPos) <= 1) continue;

                        string firstString = arr[*leftStringIdx.begin()];
                        string secondString = arr[*(++leftStringIdx.begin())];

                        string leftStringCheck = "" + upString[firstStringPos];
                        string rightStringCheck = "" + upString[secondStringPos];
                        
                        for (int i = 0; i < dist; i++) {
                            leftStringCheck += '*';
                            rightStringCheck += '*';
                        }

                        leftStringCheck += downString[firstStringPos];
                        rightStringCheck += downString[secondStringPos];
                        
                        ans += GetCandidateCnt(firstString, leftStringCheck) * GetCandidateCnt(secondString, rightStringCheck);
                    }
                }

            }


            leftStringIdx.insert(upStringIdx);
            leftStringIdx.insert(downStringIdx);
        }
    }

    cout << ans;

    return 0;
}

/* 
y = x에 대해 대칭하면 되니깐 구한 거에 *2 하는 방식으로 하고 싶은데

어떻게 구할 수 있지.

----

그냥 4개의 교차하는 문자를 뭐로 할지를 정할까.

정하고,

모든 경우의 수를 봐. 어떤 경우에 어떤 단어가 들어갈 수 있느지.

26^4 * 15^2 * 4!...

너무 많은데

---

진짜 연결해보기?

위 아래로 둘 단어 정하고
거리 벌려가면서
다른 두 문자열이 들어가는 경우의 수 구하기.

(4 * 3) * (15) * (15 * 14) * (15)
서로 다른 문자열 2개 뽑기 * 거리 * (위 아래 문자열의 어디에 다른 문자열 꼽을지) * (다른 문자열 돌면서 들어갈 수 있는 지 확인)

---

음 쉽지 않네

위 아래 선택했으면

asdfgh
--asdfgh

같이 확인 할 수도 있어야하는데 지금은 그게 없어.
*/