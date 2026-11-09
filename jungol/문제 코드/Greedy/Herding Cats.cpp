#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    int tc;

    scanf("%d", &tc);

    while (tc--) {
        int n, m;
        scanf("%d%d", &n, &m);

        vector<vector<int>> neededCatnip(m);
        vector<int> catCnt(m, 0);

        for (int i = 0; i < n; i++) {
            int pos, cnt;
            scanf("%d%d", &pos, &cnt);

            pos--;
            catCnt[pos]++;
            while (cnt--) {
                int c;
                scanf("%d", &c);
                
                neededCatnip[pos].push_back(c);
            }
        }


        vector<vector<int>> orCatnip(m), andCatnip(m);

        vector<int> catnipCnt(m+1, 0);
        for (int i = 0; i < m; i++) {
            for (const auto& catnip : neededCatnip[i]) {
                catnipCnt[catnip]++;
                if (catnipCnt[catnip] == 1) orCatnip[i].push_back(catnip);
                
                if (catCnt[i] == catnipCnt[catnip]) andCatnip[i].push_back(catnip);
            }

            for (const auto& catnip : neededCatnip[i]) {
                catnipCnt[catnip] = 0;
            }
        }


        bool ans = true;
        vector<bool> usedCatnip(m+1, false);
        int validPot = 0;

        for (int i = m-1; i >= 0; i--) {
            validPot++;

            if (catCnt[i] == 0) continue;


            bool flag = false;
            for (auto& catnip : andCatnip[i]) {
                if (usedCatnip[catnip]) continue;

                flag = true;
                usedCatnip[catnip] = true;
                validPot--;
            }

            for (auto& catnip : orCatnip[i]) {
              if (usedCatnip[catnip]) continue;

                validPot--;
                usedCatnip[catnip] = true;
            }

            if (validPot < 0 || !flag) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "yes\n" : "no\n");
    }
    return 0;
}