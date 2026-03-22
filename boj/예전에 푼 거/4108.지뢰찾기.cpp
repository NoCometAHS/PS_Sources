// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 구현
// 입력받고 인접한 칸 살펴보기

//#include <iostream>
//
//char map[100][101];
//
//int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dy[8] = { -1, -1, 0 , 1, 1, 1, 0, -1 };
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	int n, m;
//
//	std::cin >> n >> m;
//
//	while (n != 0 || m != 0) {
//		for (int i = 0; i < n; i++) {
//			std::cin >> map[i];
//
//		}
//
//		for (int i = 0; i < n; i++) {
//			for (int k = 0; k < m; k++) {
//
//				if (map[i][k] == '*') continue;
//
//				int cnt = 0;
//
//				for (int dir = 0; dir < 8; dir++) {
//					int nx = k + dx[dir], ny = i + dy[dir];
//
//					if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;
//
//					if (map[ny][nx] == '*') {
//						cnt++;
//					}
//				}
//
//				map[i][k] = cnt + '0';
//			}
//		}
//
//		for (int i = 0; i < n; i++) {
//			std::cout << map[i] << '\n';
//		}
//
//		std::cin >> n >> m;
//	}
//
//	return 0;
//}