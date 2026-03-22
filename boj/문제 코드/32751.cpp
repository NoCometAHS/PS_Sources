#include "bits/stdc++.h"

using namespace std;

int main() {

    int n, a, b, c, d;
    string str;
    cin >> n >> a >> b >> c >> d >> str;


    if (str.front() != 'a' || str.back() != 'a') {
        cout << "No";
        return 0;
    }

    bool ans = true;
    char pre = 0;
    for (auto& i : str) {
        if (i == pre) {
            ans = false;
            break;
        }

        pre = i;

        switch(i) {
            case 'a':a--; break;
            case 'b':b--; break;
            case 'c':c--; break;
            case 'd':d--; break;
        }
    }

    if (!ans || a < 0 || b < 0 || c < 0 || d < 0) {
        cout << "No";
    }
    else cout << "Yes";

    return 0;
}