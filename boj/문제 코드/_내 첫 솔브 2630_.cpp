#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

void func(int x, int y, int l, TwoVector<int>& arr, int& blue, int& white) {
    if (l == 1) {
        if (arr[y][x]) blue++;
        else white++;

        return;
    }

    int c = 0;
    for (int i = 0; i < l; i++) {
        for (int k = 0; k < l; k++) {
            c += arr[y + i][x + k];
        }
    }

    int ll = l /2;
    if (c == 0 || c == l*l)  {
        func(x,y,1, arr, blue, white);
    }
    else {
        func(x, y, ll, arr, blue, white);
        func(x+ll, y, ll, arr, blue, white);
        func(x, y+ll, ll, arr, blue, white);
        func(x+ll, y+ll, ll, arr, blue, white);
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    TwoVector<int> arr(n, vector<int>(n));
    for (auto& v : arr) for (auto& i : v) cin >> i;

    int blue = 0, white = 0;
    func(0, 0, n, arr, blue, white);

    cout << white << '\n' << blue;

    return 0;
}

/*
#include <stdio.h>

#pragma warning (disable : 4996)

#define WHITE 0
#define BLUE  1

typedef struct{
	int x;
	int y;
}Pos;


Pos temp1;
Pos temp2;

int blue_paper;
int white_paper;


void make_colorpaper(char paper[][128], Pos leftup, Pos rightdown) {

	char base_color = paper[leftup.y][leftup.x];
	
	for (int i = leftup.y; i < rightdown.y; i++) {
		for (int j = leftup.x; j < rightdown.x; j++) {
			if (paper[i][j] != base_color) goto need_to_division;
		}
	}

	if (base_color-48 == BLUE) { blue_paper++; }
	else white_paper++;

	return;

need_to_division :

	temp1 = leftup;
	temp2 = rightdown;

	//left up
	temp2.x -= (rightdown.x - leftup.x) / 2;
	temp2.y -= (rightdown.y - leftup.y) / 2;
	make_colorpaper(paper, leftup, temp2);

	temp1 = leftup;
	temp2 = rightdown;

	//left down
	temp1.y += (rightdown.y - leftup.y) / 2;
	temp1.x = leftup.x;
	temp2.x -= (rightdown.x -leftup.x)/ 2;
	temp2.y = rightdown.y;
	make_colorpaper(paper, temp1, temp2);

	temp1 = leftup;
	temp2 = rightdown;

	//right up
	temp1.x += (rightdown.x - leftup.x) / 2;
	temp1.y = leftup.y;
	temp2.x = rightdown.x;
	temp2.y -= (rightdown.y - leftup.y) / 2;
	make_colorpaper(paper, temp1, temp2);

	temp1 = leftup;
	temp2 = rightdown;

	//right down
	temp1.x += (rightdown.x - leftup.x) / 2;
	temp1.y += (rightdown.y - leftup.y) / 2;
	make_colorpaper(paper, temp1, rightdown);
}

int main(void) {
	int paper_scale;
	char color;
	char paper[128][128];

	scanf("%d", &paper_scale);
	getchar();

	for (int i = 0; i < paper_scale; i++) {
		for (int j = 0; j < paper_scale; j++) {
			color = getchar();
			paper[i][j] = color;
			getchar();
		}
	}


	temp1.x = 0;
	temp1.y = 0;
	temp2.x = paper_scale;
	temp2.y = paper_scale;
	make_colorpaper(paper, temp1, temp2);

	printf("%d\n%d", white_paper, blue_paper);

	return 0;
}

첫 맞았습니다. ㅋㅋ
*/