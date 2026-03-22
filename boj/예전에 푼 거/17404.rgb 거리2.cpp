// 변수 이름 + 개행
// 구현 / 논리 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// dp
// 양 끝에 2개 미리 정해두고 dp (x, 반례 1)
// 양 끝 2개 제외하고 dp 한 후 끝에 2개 정하기 (x, 반례 2 /)
// 양 끝 경우를 부르트포스 가자
//  원형으로 되어있다구 생각하면 될듯
// 
// dp[i][j] i 번째에 j 색을 칠 했을 때의 최소 값

// 반례 1
// 1 10 5
// 10 1 10
// 1000 1 1000
// 10 1 10
// 10 1000 10

// 반례 2
// 10 10 10
// 1000 1 1000
// 10 1 10
// 10 1 10
// 1000 1 1000
// 10 10 10

// 10 10 10
// 5 1 10
// 5 10 10
// 1 100 100
// 
//
//#include <iostream>
//
//#define INF 1000000000
//
//int n;
//int dp[1000][3] = { {INF, INF, INF}, };
//int cost[1000][3];
//
//void solve() {
//	for (int i = 1; i < n - 1; i++) {
//		for (int cur = 0; cur < 3; cur++) {
//
//			int t = dp[i - 1][cur];
//			dp[i - 1][cur] = 1e9;
//
//			dp[i][cur] = std::min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
//			dp[i][cur] += cost[i][cur];
//
//			dp[i - 1][cur] = t;
//		}
//	}
//
//	return;
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
//	}
//
//	int res = 1e9;
//	for (int i = 0; i < 3; i++) {
//		dp[0][i] = cost[0][i];
//
//		solve();
//
//		for (int k = 0; k < 3; k++) {
//			if (k == i) {
//				continue;
//			}
//			int t = dp[n - 2][k];
//			dp[n - 2][k] = 1e9;
//
//			res = std::min(res ,std::min({dp[n - 2][0], dp[n - 2][1], dp[n - 2][2]}) + cost[n - 1][k]);
//
//			dp[n - 2][k] = t;
//		}
//
//
//		dp[0][i] = 1e9;
//	}
//
//	std::cout << res;
//	return 0;
//}