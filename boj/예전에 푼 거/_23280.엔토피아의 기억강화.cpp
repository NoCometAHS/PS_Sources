// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

//
// dp
// dp[2][13] : dp[i][k] i손가락이 k에 있고 다른 손가락은 전에 눌렀던 버튼에 있을 경우에 든 채력의 최소값
// i : 0 왼손, 1 오른손
//
//#include <iostream>
//#include <algorithm>
//
//int dp[2][2][13];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//
//	int cost[2];
//	std::cin >> n >> cost[0]  >> cost[1];
//
//	for (int i = 1; i < 13; i++)dp[0][0][i] = dp[0][1][i] = dp[1][0][i] = dp[1][1][i] = 1e9;
//
//	int pre, cur;
//	std::cin >> pre;
//	dp[0][0][1] = cost[1] + (pre - 1) / 3 + std::abs(2 - (pre - 1) % 3);
//	dp[0][1][3] = cost[0] + (pre - 1) / 3 + (pre - 1) % 3;
//
//	
//
//	for (int i = 1; i < n; i++) {
//		std::cin >> cur;
//		int preToCur = std::abs((pre - 1) / 3 - (cur - 1) / 3) + std::abs((pre - 1) % 3 - (cur - 1) % 3);
//		
//
//		for (int k = 1; k < 13; k++) {
//			int kToCur = std::abs((k - 1) / 3 - (cur - 1) / 3) + std::abs((k - 1) % 3 - (cur - 1) % 3);
//
//			//왼엄지가 k에 있을 때
//			dp[i % 2][0][k] = std::min(dp[i % 2][0][k], cost[1] + preToCur + dp[(i + 1) % 2][0][k]);
//			dp[i % 2][1][pre] = std::min(dp[i % 2][1][pre], cost[0] + kToCur + dp[(i + 1) % 2][0][k]);
//
//			//오른엄지가 k에 있을 때
//			dp[i % 2][1][k] = std::min(dp[i % 2][1][k], cost[0] + preToCur + dp[(i + 1) % 2][1][k] );
//			dp[i % 2][0][pre] = std::min(dp[i % 2][0][pre], cost[1] + kToCur + dp[(i + 1) % 2][1][k]);
//
//			dp[(i + 1) % 2][0][k] = 1e9;
//			dp[(i + 1) % 2][1][k] = 1e9;
//		}
//		
//		pre = cur;
//	}
//
//	int ans = 1e9;
//	for (int i = 1; i < 13; i++) {
//		ans = std::min({ ans, dp[(n - 1) % 2][0][i], dp[(n - 1) % 2][1][i] });
//	}
//
//	std::cout << ans;
//	return 0;
//}
