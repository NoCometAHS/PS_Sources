// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 기하, dp, 비트
//
// 만들 수 있는 모든 백터 위치 백터로 만들기
// 
// dp[i][k] : i는 작은 번째에서 큰번째로 연결된 백터, k는 큰번째에서 작은 번째로 연결된 백터
// (X, 너무 늦음 20^10 정도 연산)

// 브루트 포스, 기하
// 4점의 백터의 합은 
// (ax,ay), (bx,by), (cx,cy), (dx,dy)
// ab(bx-ax, by-ax), cd(dx-cx, dy-cy);
// 두 백터의 합 (bx + dx - ax - cx, by + dy - ay - cy)
// 따라서 점 n/2개만 골라서 더하고 나머지 빼주면 됨

//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using LL = long long;
//using  LLpair = std::pair<LL, LL>;
//
//
//struct VEC {
//	LLpair _vec;
//	int usedDot;
//
//	VEC(LLpair v = { 0, 0 }, int ud = 0) : _vec(v), usedDot(ud) {}
//};
//
//
//LLpair dots[20]; int n;
//int full_dots;
//
//LL dfs(int used, int cur, int lv = 0) {
//	if (lv == n/2) {
//		LLpair ret;
//		for (int i = 0; i < n; i++) {
//			if (used & (1 << i)) {
//				ret.first += dots[i].first;
//				ret.second += dots[i].second;
//			}
//			else {
//				ret.first -= dots[i].first;
//				ret.second -= dots[i].second;
//			}
//		}
//
//		return ret.first * ret.first + ret.second * ret.second;
//	}
//	
//	LL min = 1LL << 62;
//	for (int i = cur; i < n; i++) {
//		min = std::min( min, dfs(used | (1 << i), i+1 , lv+1) );
//	}
//
//	return min;
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
//
//		std::cin >> n;
//
//		for (int i = 0; i < n; i++) {
//			std::cin >> dots[i].first >> dots[i].second;
//		}
//
//		std::cout << std::fixed;
//		std::cout.precision(7);
//		std::cout << std::sqrt(dfs(0, 0)) << '\n';
//
//	}
//
//	return 0;
//}
