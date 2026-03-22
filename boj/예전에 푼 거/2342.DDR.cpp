// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// dp
// dp[cur][5][5] : 발 위치를 나타내며 그 발위치의 최소 값을 가지고 있음
//
//
//#include <iostream>
//
//#define INF 1e9
//#define _next(x) ((x+1)%2)
//
//int cost[5][5] = {	// from to
//	{ -1, 2, 2, 2, 2},
//	{ -1, 1, 3, 4 ,3},
//	{ -1, 3, 1, 3, 4},
//	{ -1, 4, 3, 1, 3},
//	{ -1, 3, 4, 3, 1},
//};
//
//int dp[2][5][5];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	for (int i = 0; i < 5; i++) {
//		for (int k = 0; k < 5; k++) {
//			dp[1][i][k] = dp[0][i][k] = INF;
//		}
//	}
//
//	dp[0][0][0] = 1;
//
//	int num, t;
//	std::cin >> num;
//	for (t = 0; num; std::cin >> num, t = (t+1)%2) {
//		
//		for (int i = 0; i < 5; i++) {
//			for (int k = 0; k < 5; k++) {
//				if (dp[t][i][k] == INF) continue;
//
//				dp[_next(t)][i][num] = std::min(dp[_next(t)][i][num], dp[t][i][k] + cost[k][num]);
//				dp[_next(t)][num][k] = std::min(dp[_next(t)][num][k], dp[t][i][k] + cost[i][num]);
//
//				dp[t][i][k] = INF;
//			}
//		}
//
//
//	}
//
//	int min = INF;
//	for (int i = 0; i < 5; i++) {
//		for (int k = 0; k < 5; k++) {
//			min = std::min(min, dp[t][i][k]);
//		}
//	}
//
//	std::cout << min - 1;
//  return 0;
//}