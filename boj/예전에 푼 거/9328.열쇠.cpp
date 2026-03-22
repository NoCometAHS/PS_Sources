// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// bfs, 구현
//
// bfs로 입구에서 부터 탐색
// 열쇠 없으면 벡터로 잠긴 문 위치 저장
//  있으면 그냥 지나감
//
//
//
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using intpair = std::pair<int, int>;	// y, x
//
//int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
//
//std::vector<intpair> lockedDoor[26];
//bool keys[26];
//char map[102][102];
//
//void open_door(int key, std::queue<intpair>& que){
//	for (intpair i : lockedDoor[key]) {
//		que.push(i);
//		map[i.first][i.second] = '*';
//	}
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	int tc;
//	std::cin >> tc;
//
//	while (tc--) {
//		int n, m;
//		std::cin >> n >> m;
//
//		for (int i = 1; i <= n; i++) {
//			for (int k = 1; k <= m; k++) {
//				std::cin >> map[i][k];
//			}
//		}
//
//		char haveKey[27];
//		std::cin >> haveKey;
//
//		if (haveKey[0] != '0') {
//			for (int i = 0; haveKey[i]; i++) {
//				keys[haveKey[i] - 'a'] = true;
//			}
//		}
//
//
//		std::queue<intpair> que;
//		int cnt = 0;
//
//		que.push({ 0,0 });
//		while (!que.empty()) {
//			intpair cur = que.front();
//			que.pop();
//
//			for (int dir = 0; dir < 4; dir++) {
//				int nx = cur.second + dx[dir], ny = cur.first + dy[dir];
//
//				if (nx < 0 || nx >= m + 2 || ny < 0 || ny >= n + 2 || map[ny][nx] == '*') continue;
//
//				if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z' && !keys[map[ny][nx] - 'A']) {
//
//					lockedDoor[map[ny][nx] - 'A'].push_back({ ny, nx });
//					continue;
//				}
//				else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z') {
//
//					keys[map[ny][nx] - 'a'] = true;
//					open_door(map[ny][nx] - 'a', que);
//				}
//				else if (map[ny][nx] == '$') {
//					cnt++;
//				}
//
//
//				que.push({ ny, nx });
//				map[ny][nx] = '*';
//			}
//
//			//for (int i = 0; i <= n + 1; i++) {
//			//	for (int k = 0; k <= m + 1; k++) {
//			//		if (map[i][k] == 0)std::cout << '0';
//			//		else std::cout << map[i][k];
//			//	}std::cout << '\n';
//			//}std::cout << '\n';
//		}
//
//		std::cout << cnt << '\n';
//
//		cnt = 0;
//		for (int i = 0; i < 26; i++) {
//			lockedDoor[i].clear();
//			keys[i] = false;
//		}
//
//		for (int i = 0; i <= n+1; i++) {
//			for (int k = 0; k <= m+1; k++) {
//				map[i][k] = 0;
//			}
//		}
//	}
//
//}