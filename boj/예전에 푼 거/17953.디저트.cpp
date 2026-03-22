// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

//
// dp
// dp[100000][10] // dp[i][j] : i번째 날에 j번째 디저트 먹었을 때의 최대 만족감
// dp[i][j] = i-1날에 먹은 디저트중 최댓값에서 j디저트 만족감 더한 값, 단 dp[i-1][j]가 최대면 만족감에 1/2 해줘야함
//

//
//#include <iostream>
//
//int dp[100000][10];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//
//	std::cin >> n >> m;
//
//	for (int i = 0; i < m; i++) {
//		for (int k = 0; k < n; k++) {
//			std::cin >> dp[k][i];
//		}
//	}
//
//
//	for (int i = 1; i < n; i++) {
//		for (int k = 0; k < m; k++) {
//
//			int max = 0;
//			for (int select = 0; select < m; select++) {
//				int temp = dp[i - 1][select] + (select == k ? dp[i][k] / 2 : dp[i][k]);
//
//				max = std::max(temp, max);
//			}
//
//			dp[i][k] = max;
//		}
//	}
//
//
//	int ans = 0;
//	for (int i = 0; i < m; i++) {
//		ans = std::max(ans, dp[n - 1][i]);
//	}
//
//	std::cout << ans;
//
//	return 0;
//}