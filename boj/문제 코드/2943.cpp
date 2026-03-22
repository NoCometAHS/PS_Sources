#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    int sqrtN = sqrt(n);
    vector<int> cup(sqrtN+1, 0), box(n, 0);

    while (m--) {
        int s, a;
        cin >> s >> a;
        a--;

        int lt = a, rt = a + s-1, res = 0;

        while (lt % sqrtN && lt <= rt) {
            box[lt]++;

            res += box[lt];
            lt++;
        }

        while (rt != n-1 && (rt+1) % sqrtN && lt <= rt) {
            box[rt]++;

            res += box[rt];
            rt--;
        }

        if (lt < rt) {
            for (int i = lt / sqrtN; i <= rt/sqrtN; i++) {
                cup[i]++;

                res += cup[i];
            }
        }

        cout << res << '\n';
    }
    return 0;
}


/*
k번째에 쓴 모든 컵과 성냥갑에 있는 성냥 개수인가?]

성냥갑에도 그럼 성냥이 남아있나?
*/