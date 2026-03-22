//// 변수 이름 + 개행
//// 논리 / 구현 명세
//// 구현은 쉽게 -> 명료히
//// 먼저 생각하기
//
////
//// 정렬, greedy
////
//
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//
//int arr[500500];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	int n;
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> arr[i];
//	}
//
//	std::sort(arr, arr + n);
//
//	long long ans = 0;
//	for (int i = 0; i < n; i++) {
//		ans += std::abs(arr[i] - i - 1);
//	}
//
//	std::cout << ans;
//	return 0;
//}