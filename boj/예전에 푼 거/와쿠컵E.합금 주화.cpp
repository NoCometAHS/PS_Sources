//
// 수학
// 
// 밀도 = 질량 / 부피
// 
// 금속 m1, m2
// m1 부피 = m1/밀도, m2 부피 = m2 / 밀도
// 
//m1 < m2
//주화 질량 * x = m2
//주화 질량 * (1-x) = m1
// 
// 주화 질량 = m
// 
// 주화 밀도 = ( mx + m(1-x) ) / (mx / 밀도 + m(1-x) / 밀도) 
// == 1 / (x / m1밀도 + (1-x) / m2밀도)

//#include <iostream>
//#include <algorithm>
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	double v1, v2, x;
//	std::cin >> v1 >> v2 >> x;
//	x /= 100;
//
//	if (v1 < v2) std::swap(v1, v2);
//
//	std::cout << std::fixed;
//	std::cout.precision(7);
//	std::cout << 1 / (x / v1 + (1 - x) / v2);
//
//	return 0;
//}