#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    char month[20];
    int day, hour, min, year;


    scanf("%s %2d, %4d %2d:%2d", month, &day, &year, &hour, &min);


    LL sum = 24 * 60;
    bool f = false;

    if ((year % 4  == 0 && year % 100 != 0) || year % 400 == 0) {
        sum *= 366;
        f = true;
    }
    else {
        sum *= 365;
    }

    map<string, int> MonthToInt{{"January", 0}, {"February", 1}, {"March", 2},{"April", 3},{"May", 4},{"June", 5},{"July", 6},{"August", 7},{"September", 8},{"October", 9}, {"November", 10} , {"December", 11}};
    vector<LL> days{0,31,28,31,30,31,30,31,31,30,31,30};
    if (f) {
        days[2] = 29;
    } 

    for (int i = 1; i < days.size(); i++) {
        days[i] += days[i-1];
    }

    LL cur = (days[MonthToInt[month]] + day - 1) * 24 * 60 + hour * 60 + min;

    cout << fixed;

    cout.precision(10);

    cout << 100.0 * cur / sum;




    return 0;
}
