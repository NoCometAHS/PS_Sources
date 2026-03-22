//// 변수 이름 + 개행
//// 논리 / 구현 명세
//// 구현은 쉽게 -> 명료히
//// 먼저 생각하기
//
////
//// 정렬
////
//// 
//// + 홀 짝
//// 홀짝 홀
//// 짝홀 짝
////
//// - 홀 짝
//// 홀짝 홀
//// 짝홀 짝
//// 
//// 한점에서 오른쪽으로만 볼 꺼임, 왼쪽의 점이 정답이라면 왼쪽 점 볼때 이미 구했음
//// 홀수의 최소 길이 구하기
//// // 한 점이 홀수면 가장 가까운 짝수 구하기
//// // 한 점이 짝수면 가장 가까운 홀수 구하기
//// 
//// 짝수의 최소 길이 구하기
//// // 한점이 홀수면 가장 가까운 홀수 구하기
//// // 한점이 짝수면 가장 가까운 짝수 구하기
////
//// 오른쪽에서부터 왼쪽으로 한점에서 가장 가까운 짝,홀수 구할거야
////
//
//
//#include <iostream>
//#include <algorithm>
//
//int nearOdd[500500];
//int nearEven[500500];
//int arr[500500];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> arr[i];
//	}
//
//	std::sort(arr, arr + n);
//	nearOdd[n-1] = -1;
//	nearEven[n-1] = -1;
//
//	for (int i = n - 2; i >= 0; i--) {
//		nearOdd[i] = (arr[i+1] % 2 ? i+1 : nearOdd[i+1]);
//		nearEven[i] = (arr[i + 1] % 2 ? nearEven[i + 1] : i + 1);
//	}
//
//	int evenMin = 2e9+1, oddMin = 2e9+1;
//	for (int i = 0; i < n - 1; i++) {
//		if (arr[i] % 2) {
//			if (nearOdd[i] != -1) {
//				evenMin = std::min(evenMin, arr[nearOdd[i]] - arr[i]);
//			}
//			if (nearEven[i] != -1) {
//				oddMin = std::min(oddMin, arr[nearEven[i]] - arr[i]);
//			}
//		}
//		else {
//			if (nearEven[i] != -1) {
//				evenMin = std::min(evenMin, arr[nearEven[i]] - arr[i]);
//			}
//			if (nearOdd[i] != -1) {
//				oddMin = std::min(oddMin, arr[nearOdd[i]] - arr[i]);
//			}
//		}
//	}
//
//	std::cout << (evenMin == 2e9+1 ? -1 : evenMin) << ' ' << (oddMin == 2e9+1 ? -1 : oddMin);
//	return 0;
//}