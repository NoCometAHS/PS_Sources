//
// 그리디
// 
// n x
// n과 n-1을 양 벽으로 세운 경우가 체울 수 있는 물의 최대 양
// = (n-2)*(n-1)/2
// x가 위의 수보다 크면 -1
//
// (n-2)*(n-1)/2 - x, n을 제외한 막대부터 차례로 n 높이 막대 오른쪽에 놔둠
//
//
//#include <iostream>
//#include <vector>
//
//using LL = long long;
//
//int main() {
//	
//	LL n, m;
//	std::cin >> n >> m;
//	
//	LL max = (n - 2) * (n - 1) / 2;
//
//	if (max < m) {
//		std::cout << -1;
//		return 0;
//	}
//
//	std::vector<int> bars, outBars;
//	bars.reserve(1100100), outBars.reserve(1100100);
//	
//	LL leftWater = max - m;
//	
//	for (int i = 1; i < n-1; i++) {
//		if ((n-1-i) <= leftWater) {
//			outBars.push_back(i);
//			leftWater -= n - 1 - i;
//		}
//		else {
//			bars.push_back(i);
//		}
//	}
//
//	for (const int& bar : outBars) {
//		std::cout << bar << ' ';
//	}
//	std::cout << n - 1 << ' ';
//	for (const int& bar : bars) {
//		std::cout << bar << ' ';
//	}
//	std::cout << n;
//
//	return 0;
//}