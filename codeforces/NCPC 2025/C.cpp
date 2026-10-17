#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    char stDay_[4];
    int stH, stM;

    char enDay_[4];
    int enH, enM;

    scanf("%s %d:%d", stDay_, &stH, &stM);
    scanf("%s %d:%d", enDay_, &enH, &enM);

    map<string, int> days({{"Mon" , 0}, {"Tue" , 1},{"Wed" , 2},{"Thu" , 3},{"Fri" , 4},{"Sat" , 5},{"Sun" , 6}});
    int stDay = days[string(stDay_)];
    int enDay = days[string(enDay_)];

    int durM = enM - stM;
    if (durM < 0) {
        stH++;
        durM += 60;
    }

    int durH = enH - stH;
    if (durH < 0) {
        stDay++;
        durH += 24;
    }

    int durD = enDay - stDay;
    
    if (durD < 0) {
        durD += 7;
    }


    vector<string> ans;
    ans.push_back(to_string(durD) + " day");
    if (durD > 1) ans.back().push_back('s');

    ans.push_back(to_string(durH) + " hour");
    if (durH > 1) ans.back().push_back('s');

    ans.push_back(to_string(durM) + " minute");
    if (durM > 1) ans.back().push_back('s');

    for (auto it = ans.begin(); it != ans.end();) {
        if (it->front() == '0') {
            while (it!= ans.end() and it->front() == '0') it = ans.erase(it);
        }
        else {
            it++;
        }
    }


    if (ans.size() == 1) {
        cout << ans.front();
        return 0;
    }
    else if (ans.size() == 2) {
        cout << ans.front() << " and " << ans.back();
        return 0;
    }
    else if (ans.size() == 0) {
        cout << "7 days";
    }
    else {
        cout << ans.front();
        for (int i = 1; i < 3; i++) {
            cout << ", " << ans[i];
        }
        return 0;
    }

    return 0;
}