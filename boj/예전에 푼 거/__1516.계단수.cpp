// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 비트 마스킹, dp
// 
// dp[exist][cnt][end num] // exist 있는 숫자 비트로 저장, cnt 남은 개수, end num 그렇게 만들어진 수열에서 마지막 숫자
//	왼쪽에서 부터 채워진다고 생각
//
// 피보나치식 dp는 함수 먼저 만들고 생각하는 것이 좋은 것 같음
//
//#include <iostream>
//
//using LL = long long;
//
//#define FullNum 0b1111111111
//#define BigNum 1000000000
//
//LL dp[1 << 10][100][10];
//int n;
//
//LL _dfs(int cur, int exist, int lv) {
//	if (dp[exist][n - lv][cur]) return dp[exist][n - lv][cur];
//	if (lv == n) {
//		return (exist == FullNum ? 1 : 0);
//	}
//
//	int res = 0;
//
//	if (cur + 1 < 10)
//		res = (res + _dfs(cur + 1, exist | (1 << (cur + 1)), lv + 1))%BigNum;
//	if (cur - 1 >= 0)
//		res = (res + _dfs(cur - 1, exist | (1 << (cur - 1)), lv + 1))%BigNum;
//
//	return dp[exist][n-lv][cur] = res;
//}
//
//
//LL dfs() {
//	int res = 0;
//	for (int i = 1; i < 10; i++) {
//		res = (res + _dfs(i, 1 << i, 1))%BigNum;
//	}
//
//	return res;
//}
//
//
//int main() {
//	std::cin >> n;
//
//	for (int i = 0; i < 10; i++) {
//		dp[FullNum & (~(1 << i))][1][i] = 1;
//	}
//
//	std::cout << dfs();
//
//	return 0;
//}