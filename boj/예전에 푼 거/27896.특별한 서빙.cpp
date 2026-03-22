// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

//
// dp + 역추적
// dp[n][2]  : dp[i][[0, 1]] : i번째 서빙할때 0이면 파묻튀 서빙 1이면 가지 서빙 할때 m을 넘지 않은 최대 불만도 (?, 이거 맞나?)
//				가지개수
// 최소불만도
//(x, 순서대로 해야해서 dp로 하면 중간에 넘는지 보기 어려움, 쌓아가는 방식도 영;;)
//
// 그리디, pq
// pq에 만족도 넣어두기
// 순서대로 파묻튀 주기
// // 만족도 초가되는 시점이 왔을 때 pq의 탑에서 나온 만족감 * -2해서 더하기
// // 만족도 초가되지 않을 때까지 가지 주기
// 
//
//#include <iostream>
//#include <queue>
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//
//	int curState = 0, num, ans = 0;
//	std::priority_queue<int> pq;
//
//	while (n--) {
//		std::cin >> num;
//		
//		curState += num;
//		pq.push(num);
//
//		while (curState >= m) {
//			ans++;
//			curState -= pq.top() * 2;
//			pq.pop();
//		}
//	}
//
//	std::cout << ans;
//	return 0;
//}