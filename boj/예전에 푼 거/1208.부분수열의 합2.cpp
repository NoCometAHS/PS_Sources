// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 구현 (x, 더하나 안더하나 결과는 같음)
// 모든 수에 1,000,000에 더하기
// s 보다 작으면 앞으로 한칸, 크면 뒤에서 앞으로
// s와 같으면 앞으로 한칸
// 
// 브루트 포스  (x, 연속된 부분 수열이 아니라서 불가능)
// n 작아서 ㄱㅊㄱㅊ
//
// dp
// 숫자 체크 방식
//
//
// 다른 방식 있는거 같은데? ㅅㅂ

//#include <iostream>
//
//using LL = long long;
//
//constexpr int ZERO = 4000000;
//
//LL dp[2][8000001];
//
////4000000 기준
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	int n, s;
//	std::cin >> n >> s;
//
//	for (int i = 0, num; i < n; i++) {
//		std::cin >> num;
//
//		for (int k = 0; k <= 8000000; k++) {
//			if (k + num < 0 || k+num > 8000000) continue;
//			
//			dp[(i+1)%2][k+num] = dp[i%2][k] + dp[i%2][k+num];
//		}
//
//
//		dp[(i+1)%2][ZERO + num] += 1;
//	}
//	
//	//for (int i = ZERO - 10; i <= ZERO + 10; i++) std::cout << dp[i] << ' ';
//
//	std::cout << dp[n%2][s + ZERO];
//
//	return 0;
//}