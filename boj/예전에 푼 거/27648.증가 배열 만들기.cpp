// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 수학
// 최소 n+m-1의 숫자까지 쓸 수 있어야 증가 배열 가능
// arr[i][j] = I+j+1
//

//#include <iostream>
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cout.tie(nullptr);
//	std::cin.tie(nullptr);
//
//	int n, m, num;
//	std::cin >> n >> m >> num;
//
//	if (num < n + m - 1) {
//		std::cout << "NO";
//	}
//	else {
//		std::cout << "YES\n";
//		for (int i = 0; i < n; i++) {
//			for (int k = 0; k < m; k++) {
//				std::cout << i + k + 1 << ' ';
//			}
//			std::cout << '\n';
//		}
//	}
//
//	return 0;
//}