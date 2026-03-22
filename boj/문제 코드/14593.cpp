#include "bits/stdc++.h"

using namespace std;

struct submit{
    int s,c, l, n; 
};

int main() {
    int n;
    cin >> n;
    vector<submit> arr;

    for (int i = 0; i < n; i++) {
        int s, c, l;
        cin >> s >> c >> l;

        arr.push_back({s,c,l, i+1});
    }

    sort(arr.begin(), arr.end(), [](submit a, submit b) {
        if (a.s == b.s) {
            if (a.c == b.c) return a.l < b.l;
            return a.c < b.c;
        }
        return a.s > b.s;
    });

    cout << arr.front().n;

    

    return 0;
}