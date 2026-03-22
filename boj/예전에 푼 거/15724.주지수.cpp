////
//// 누적함
//// 
//// 왼쪽위 행,열, 오른쪽 아래 행,열
////
//
//
//#include <iostream>
//#include <cassert>
//
//int popul[1025][1025];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//
//	std::cin >> n >> m;
//
//	for (int i = 1; i <= n; i++) {
//		for (int k = 1; k <= n; k++) {
//			std::cin >> popul[i][k];
//
//			popul[i][k] += popul[i][k - 1] + popul[i - 1][k] - popul[i - 1][k - 1];
//		}
//	}
//
//	int tc;
//	std::cin >> tc;
//
//	int x1, y1, x2, y2;
//	while (tc--) {
//		std::cin >> y1 >> x1 >> y2 >> x2;
//
//		std::cout << popul[y2][x2] - popul[y2][x1 - 1] - popul[y1 - 1][x2] + popul[y1 - 1][x1 - 1] << '\n';
//	}
//
//	return 0;
//}