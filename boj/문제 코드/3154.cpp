#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;


int main() {
    vector<iipair> position(10);
    position[0] = {3,1};
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            position[i*3 + k+1] = {i, k};
        }
    } 

    auto GetEffort = [&](int f, int t) {return abs(position[f].first - position[t].first) + abs(position[f].second - position[t].second);};

    int hh, mm;
    scanf("%d:%d", &hh, &mm);

    int mn = 1e9;
    string ans;
    for (int h = hh; h < 100; h+= 24) {
        for (int m = mm; m < 100; m+=60) {
            string sh = to_string(h);
            string sm = to_string(m);

            if (sh.length() == 1) sh.insert(sh.begin(), '0');
            if (sm.length() == 1) sm.insert(sm.begin(), '0');

            string res = sh + sm;

            int sum = 0;
            char cur = res[0];
            for (int i = 1; i < res.length(); i++) {
                sum += GetEffort(cur - '0', res[i] - '0');
                cur = res[i];
            }

            if (mn > sum) {
                mn = sum;
                ans = sh + ":" + sm;
            }
        }
    }

    printf("%s", ans.c_str());
    return 0;
}
// 시는 24를 나눈 나머지
// 분은 60을 나눈 나머지

/*
그냥 모든 시각을 브포 하면 될 것 같은데
*/