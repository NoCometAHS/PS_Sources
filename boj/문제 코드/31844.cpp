#include "bits/stdc++.h"

using namespace std;

int main() {
    int goal, box, robot;

    for (int i = 0; i < 10; i++) {
        char ch;
        cin >> ch;

        if (ch == '@') {
            robot = i;
        }
        else if(ch == '!') {
            goal = i;
        }
        else if(ch == '#') {
            box = i;
        }
    }

    int ans = -1;
    if (robot < box && box < goal) {
        ans = goal - robot - 1;
    }
    else if (goal < box && box < robot){
        ans = robot - goal - 1;
    }

    cout << ans;

    return 0;
}