// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기
//greedy

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int arr[1000001];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 1, t; i <= n; i++) {
//		std::cin >> arr[i];
//
//		arr[i] += arr[i - 1];
//	}
//
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		
//		int maxPos = i+1;
//		for (int k = i + 2; k <= n; k++) {
//			if (arr[maxPos] - arr[maxPos-1] < arr[k] - arr[k-1]) {
//				maxPos = k;
//			}
//		}
//		
//		ans += -(arr[maxPos-1] - arr[i]) + (arr[maxPos] - arr[maxPos-1])*(maxPos-i-1);
//
//		i = maxPos - 1;
//	}
//
//	std::cout << ans;
//
//	return 0;
//}