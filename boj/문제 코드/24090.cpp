#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;


int n, m;
int swapCount = 0;
iipair ans;

int partition(vector<int>& arr, int l, int r);

void quick(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = partition(arr, l, r);
        quick(arr, l, m-1);
        quick(arr, m+1, r);
    }
}

int partition(vector<int>& arr, int l, int r) {
    int x = arr[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            if (++swapCount == m) {
                ans.first = arr[j];
                ans.second = arr[i+1];
            }

            swap(arr[++i], arr[j]);
        }
    }

    if (i + 1 != r) {
        if (++swapCount == m) {
            ans.first = arr[r];
            ans.second = arr[i+1];
        }

        swap(arr[i+1], arr[r]);
    }

    return i + 1;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<int> arr(n);

    for (auto& i : arr) cin >> i;

    quick(arr, 0, n-1);

    auto& [one, other] = ans;
    
    if (swapCount < m) 
        cout << -1;
    else if (one < other)
        cout << one << ' ' << other;
    else 
        cout << other << ' ' << one;

    return 0;
}
