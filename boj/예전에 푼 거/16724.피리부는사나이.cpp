// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

//
// 밖으로 나가는 이동이 없어서 무조건 사이클을 이루거나 포함 됨 
// 
// dfs, 분리 집합
// 사이클을 1개씩 찾아감. 사이클 찾았으면 safe zone cnt++
// 다른 사이클 찾는 중 다른 집합과 합쳐지면 집합 합치고 넘어가기
//

//#include <iostream>
//
////int setTree[1000000];
//char map[1000][1001];
//int chk[1000][1000];
//
//int dx[26], dy[26];
//
//int dfs(int x, int y, int setNum) {
//	int nx = x + dx[map[y][x] - 'A'], ny = y + dy[map[y][x] - 'A'];
//	chk[y][x] = setNum;
//
//	if (chk[ny][nx]) {
//		if (chk[ny][nx] == setNum) {
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}
//	else {
//		return dfs(nx, ny, setNum);
//	}
//
//}
//
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	int n, m;
//
//	std::cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> map[i];
//
//	}
//
//	dx['R' - 'A'] = 1, dy['R' - 'A'] = 0;
//	dx['L' - 'A'] = -1, dy['L' - 'A'] = 0;
//	dx['D' - 'A'] = 0, dy['D' - 'A'] = 1;
//	dx['U' - 'A'] = 0, dy['U' - 'A'] = -1;
//
//	int setNum = 1, ans = 0;
//	for (int i = 0; i < n; i++) {
//		for (int k = 0; k < m; k++) {
//			if (chk[i][k]) continue;
//
//			ans += dfs(k, i, setNum++);
//		}
//	}
//
//
//	std::cout << ans;
//
//	return 0;
//}