#include "bits/stdc++.h"

using namespace std;

int main() {

    int n;
    cin >> n;

    int a= 0, b = 0;
    while (n--) {
        int s, c;
        cin >> s >> c;

        a += s > c;
        b += s < c;
    }
    cout << a << ' ' << b;
    return 0;
}