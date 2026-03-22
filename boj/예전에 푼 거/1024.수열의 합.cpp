// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

//
// 이진 탐색, 브포
// 
// 길이가 n부터 100까지 보면서 답이 있는지 확인
// 이진 탐색으로 0 ~ 500000000까지 수열 시작하는 수 찾아
//
//
//#include <iostream>
//using LL = long long;
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//
//	std::cin >> n >> m;
//
//	int ans = -1, length;
//	for (length = m; length < 101 && ans < 0; length++) {
//		LL lt = 0, rt = 500000000, m;
//
//		while (lt <= rt) {
//			m = (lt + rt) / 2;
//			
//			LL res = (m + length - 1) * (m + length) / 2 - (m - 1) * m / 2;
//			
//			if (res < n) {
//				lt = m + 1;
//			}
//			else if (res > n) {
//				rt = m - 1;
//			}
//			else {
//				ans = m;
//				break;
//			}
//		}
//	}
//
//	length--;
//
//	if (ans == -1) {
//		std::cout << -1;
//	}
//	else {
//		for (int i = ans; i < ans + length; i++) {
//			std::cout << i << ' ';
//		}
//	}
//
//	return 0;
//}