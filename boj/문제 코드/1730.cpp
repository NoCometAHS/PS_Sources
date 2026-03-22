#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string str; 
    cin >> n >> str;

    TwoVector<char> board(n, vector<char>(n, '.'));
    int x = 0, y = 0;
    for (auto& order : str) {
        int nx = x, ny = y;

        if (order == 'D') {
            ny++;
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (board[y][x] == '+' || board[y][x] == '-') board[y][x] = '+';
            else board[y][x] = '|';

            if (board[ny][nx] == '+' ||board[ny][nx] == '-') board[ny][nx] = '+';
            else board[ny][nx] = '|';
        }
        else if (order == 'R') {
            nx++;

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (board[y][x] == '+' || board[y][x] == '|') board[y][x] = '+';
            else board[y][x] = '-';

            if (board[ny][nx] == '+' ||board[ny][nx] == '|') board[ny][nx] = '+';
            else board[ny][nx] = '-';
        }
        else if (order == 'U') {
            ny--;
            

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (board[y][x] == '+' || board[y][x] == '-') board[y][x] = '+';
            else board[y][x] = '|';

            if (board[ny][nx] == '+' ||board[ny][nx] == '-') board[ny][nx] = '+';
            else board[ny][nx] = '|';
        }
        else {
            nx--;

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            
            if (board[y][x] == '+' || board[y][x] == '|') board[y][x] = '+';
            else board[y][x] = '-';
            
            if (board[ny][nx] == '+' || board[ny][nx] == '|') board[ny][nx] = '+';
            else board[ny][nx] = '-';
        }

        x = nx, y = ny;
    }

    for (auto& v: board) {
        for (auto& ch : v) cout << ch;
        cout << '\n';
    }
    return 0;
}
