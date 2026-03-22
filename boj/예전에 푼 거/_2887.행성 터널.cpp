// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// mst, 정렬
// x에대해 정렬
// 차례대로 i 행성, i+1 행성의 거리를 구함
// y, z에 대해서도 똑같이
// 구한 거리들 정렬 후 mst
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//struct DIR {
//	int f;
//	int t;
//	int c;
//
//	DIR(int f, int t, int c) : f(f), t(t), c(c){}
//	bool operator<(const DIR& a) const {
//		return c < a.c;
//	}
//};
//
//using intpair = std::pair<int, int>;
//
//int setTree[100000];
//
//int find_par(int cur) {
//	if (cur == setTree[cur]) return cur;
//	else return setTree[cur] = find_par(setTree[cur]);
//}
//
//void union_set(int a, int b) {
//	a = find_par(a), b = find_par(b);
//
//	setTree[a] = b;
//
//	return;
//}
//
//intpair pos[3][100000];
//std::vector<DIR> conn;
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//	std::cout << conn.max_size();
//
//	for (int i = 0; i < n; i++) {
//		setTree[i] = i;
//		std::cin >> pos[0][i].first >> pos[1][i].first >> pos[2][i].first;
//		pos[0][i].second = pos[1][i].second = pos[2][i].second = i;
//	}
//
//	for (int i = 0; i < 3; i++) {
//		std::sort(pos[i], pos[i] + n);
//
//		for (int k = 0; k < n - 1; k++) {
//			conn.push_back({ pos[i][k].second, pos[i][k+1].second, std::abs(pos[i][k].first - pos[i][k + 1].first)});
//		}
//	}
//
//	std::sort(conn.begin(), conn.end());
//
//	int res = 0;
//
//	for (const DIR& dir : conn) {
//		if (find_par(dir.f) == find_par(dir.t)) continue;
//
//		res += dir.c;
//
//		union_set(dir.f, dir.t);
//	}
//
//	std::cout << res;
//
//	return 0;
//}