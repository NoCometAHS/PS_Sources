// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 백트래킹, 구현
// 구슬 어디로 움직이는 지 구하는 함수
// dfs로 움직이기 전 구슬 위치 저장시키고 움직이기
// 10 6
//######
//#....#
//#....#
//#....#
//#....#
//#....#
//#....#
//#.O..#
//###BR#
//######
//
//// bfs로 할껄 ㅅㅂ
//
//#include <iostream>
//#include <algorithm>
//
//using intpair = std::pair<int, int>; // y, x
//
//#define INF 1e9
//
//char map[10][10]; 	int n, m;
//int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
//
//intpair ball[2], goal;
//
//intpair move_to(int to, int x, int y) {
//	do {
//		x += dx[to];
//		y += dy[to];
//	} while (map[y][x] == '.');
//
//	if (x == goal.second && y == goal.first) {
//		return { 0, 0 };
//	}
//	else {
//		return { y - dy[to], x - dx[to] };
//	}
//}
//
//int dfs(int lv = 0) {
//	if (lv == 10) {
//		return INF;
//	}
//
//	//std::cout << lv + 1 << '\n';
//	//for (int i = 0; i < n; i++) {
//	//	for (int k = 0; k < m; k++) {
//	//		std::cout << map[i][k];
//	//	}std::cout << '\n';
//	//}std::cout << '\n';
//	//system("pause");
//
//
//	int min = INF;
//
//	intpair curBallPos[2];
//	curBallPos[0] = ball[0], curBallPos[1] = ball[1];
//
//	for (int i = 0; i < 4; i++) {
//		int curBall = 0;
//		intpair nPos = move_to(i, curBallPos[0].second, curBallPos[0].first);
//
//		if (map[nPos.first + dy[i]][nPos.second + dx[i]] == 'B') {
//			curBall++;
//		}
//
//		intpair res1 = move_to(i, ball[curBall].second, ball[curBall].first);
//		map[curBallPos[curBall].first][curBallPos[curBall].second] = '.';
//		if (res1.first) map[res1.first][res1.second] = (curBall ? 'B' : 'R');
//
//		intpair res2 = move_to(i, ball[(curBall + 1) % 2].second, ball[(curBall + 1) % 2].first);
//		map[curBallPos[(curBall + 1) % 2].first][curBallPos[(curBall + 1) % 2].second] = '.';
//		if (res2.first) map[res2.first][res2.second] = ((curBall + 1) % 2 ? 'B' : 'R');
//		
//		if ((res1.first == 0 && res2.first != 0 && curBall == 0)) {
//			if (res1.first) map[res1.first][res1.second] = '.';
//			if (res2.first) map[res2.first][res2.second] = '.';
//
//			map[curBallPos[0].first][curBallPos[0].second] = 'R';
//			map[curBallPos[1].first][curBallPos[1].second] = 'B';
//
//
//			return lv+1;	
//		}
//
//		ball[curBall] = res1, ball[(curBall + 1) % 2] = res2;
//
//		if (res1.first && res2.first) {
//			int ret = dfs(lv + 1);
//			min = std::min(ret, min);
//		}
//
//		ball[curBall] = curBallPos[curBall], ball[(curBall + 1) % 2] = curBallPos[(curBall+1)%2];
//
//		if (res1.first) map[res1.first][res1.second] = '.';
//		if (res2.first) map[res2.first][res2.second] = '.';
//
//		map[curBallPos[0].first][curBallPos[0].second] = 'R';
//		map[curBallPos[1].first][curBallPos[1].second] = 'B';
//	}
//
//	
//	return min;
//}
//
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	std::cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//		for (int k = 0; k < m; k++) {
//			std::cin >> map[i][k];
//			if (map[i][k] == 'R') {
//				ball[0].first = i;
//				ball[0].second = k;
//			}
//			else if (map[i][k] == 'B') {
//				ball[1].first = i;
//				ball[1].second = k;
//			}
//			else if (map[i][k] == 'O') {
//				goal.first = i;
//				goal.second = k;
//			}
//		}
//	}
//	int ans = dfs();
//	std::cout << (ans >= INF ? -1 : ans );
//
//	return 0;
//}
