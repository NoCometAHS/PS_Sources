#include "bits/stdc++.h"

using namespace std;

int main() {

    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string str;
        getline(cin, str);

        stringstream ss(str);

        string s;
        while (ss >> s) {
            if (s.size() == 4) {
                cout <<"**** ";
            }
            else {
                cout << s << ' ';
            }
        }

        cout << "\n\n";
    }
    return 0;
}