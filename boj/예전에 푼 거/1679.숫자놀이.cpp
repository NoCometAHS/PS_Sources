//
// dp
// O(50*1000*1000) = O(50,000,000)
// dp[50,000] =  dp[i] : 숫자가 i를 만드는데 쓴 최소 숫자 개수
//

//#include <iostream>
//
//int dp[50500];
//int nums[1100];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> nums[i];
//	}
//
//	int m;
//	std::cin >> m;
//
//	int i;
//	for (i = 1; i <= 50000; i++) {
//		int min = 51;
//
//		for (int k = 0; k < n; k++) {
//			if (i - nums[k] < 0) break;
//
//			min = std::min(min, dp[i - nums[k]]);
//		}
//
//		if (min >= m) break;
//
//		dp[i] = min + 1;
//	}
//
//	std::cout << (i % 2 ? "jjaksoon" : "holsoon") << " win at " << i;
//
//	return 0;
//}