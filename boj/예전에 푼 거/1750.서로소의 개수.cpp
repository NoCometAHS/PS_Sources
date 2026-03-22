//
// 수학, 쌓아가는 dp
// 
// 최대공약수
// dp[100100] : dp[i], 최대 공약수가 i가 되는 집합의 개수
//

//#include <iostream>
//
//#define PRIME 10000003
//
//int gcd(int a, int b) {
//	while (a % b) {
//		int temp = a % b;
//		a = b;
//		b = temp;
//	}
//
//	return b;
//}
//
//int dp[100100];
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 0, num; i < n; i++) {
//		std::cin >> num;
//		for (int k = 1; k <= 100000; k++) {
//			int gcdV = gcd(num, k);
//			dp[gcdV] = (dp[gcdV] + dp[k])%PRIME;
//		}
//		dp[num]++;
//	}
//
//	std::cout << dp[1];
//	return 0;
//}