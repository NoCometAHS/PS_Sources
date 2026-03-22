// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 백트레킹
// 자신이 정해지면 그 위를 보고 불가능하면 그 전 친구로 바로 튀~어~ (x, 시간 초과)
// 
// dp
// 1행부터 하나씩 채울거임
// n번째 행 이후는 n행 이전이 고정되어 있다는 것이니 최댓값을 구할 수 있음
// n행 이전이 바뀌면 n행 이후 최댓값도 바뀔 가능성 있음 (x, 논리적으로 틀림)
// 
// dp, 백트레킹
// dp[i][num] : 1 ~ column[i]까지 i-1행에 들어간 수가 모두 num일때 i행 ~ 모든 박스를 채울 수 있는 경우의 수  (x, 아직도 느려)
//
// dp, 백트레킹
// dp[i] : 1 ~ column[i]까지 i-1행에 수가 적당히 들어갔을 때 i행 ~ 모든 박스를 채울 수 있는 경우의 수
// 1 ~ column[i]까지 i-1행에 들어갔으면 i-1행에서 column[i] ~ column[i-1]열까지 숫자를 바꿔도 그 이후에 채울 수 있는 경우의 수는 항상 반복됨
// 
// 2 2 1
// 4
// 3*4 + 3*2 + 2*1 = 12 + 6 + 2
//
// 피보나치식 반복(계산에서 반복되는 부분 찾기)
// 
// 
//
//#include <iostream>
//#include <algorithm>
//
//int arr[8][8], n, row;	// 1, 1시작
//int column[8];
//int dp[9];
//
//int dfs(int x, int y) {
//	if (y > row) {
//		std::cout << 'a';
//		return 1;
//	}
//	if (x > column[y]) {
//		if (dp[y + 1] != -1) {
//			return dp[y + 1];
//		}
//		else {
//			return dp[y + 1] = dfs(1, y + 1);
//		}
//	}
//
//
//	int ret = 0;
//	for (int i = std::max(arr[y - 1][x] + 1, arr[y][x - 1]); i <= n; i++) {
//		if (y + 1 <= row && x <= column[y + 1] && i + 1 > n) {
//			break;
//		}
//
//		if (x <= column[y + 1]) dp[y + 1] = -1;
//
//		arr[y][x] = i;
//
//		ret += dfs(x + 1, y);
//	}
//
//	return ret;
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	while (std::cin >> row) {
//
//		for (int i = 1; i <= row; i++) {
//			std::cin >> column[i];
//		}
//
//		for (int i = 0; i < 9; i++) {
//			dp[i] = -1;
//		}
//
//		std::cin >> n;
//		std::cout << dfs(1, 1) << '\n';
//
//
//	}
//
//	return 0;
//}