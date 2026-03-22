////
//// 변수 이름 + 개행
//// 논리 / 구현 명세
//// 구현은 쉽게 -> 명료히
//// 먼저 생각하기
////
//
//// 기하, 수학
//// LWH = A^3 * N
//// LWH/N = A^3
//// (x, 문제 잘못 읽음, 상자 그냥 전부 넣어야 하는거)
//// 
//// 
//// 넓이가지고 이진 탐색?
//// 큰상자 길이 넓이로 나눈 몫의 곲이 n보다 크면 넣기 가능
//// 
//// 상자 개수로 이진 탐색?
////
//
////
//// 결국 찍어 넘기는 방법으로 넘겼음
//// 
////
//
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//
//using LL = long long;
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	double n, l, w, h;
//
//	std::cin >> n >> l >> w >> h;
//
//
//	double lt = 0, rt = std::min({l, w, h}), m, ans;
//	
//
//	for (int i = 0; i < 100; i++) {	//log2(1e9)는 대충 30 그니깐 30넘게 좀더 돌려서 대충 맞추기
//		m = (lt + rt) / 2;
//		//std::cout << m << '\n';
//		LL cnt = std::floor(l / m) * std::floor(w / m) * std::floor(h / m);
//
//		if (cnt < n) {
//			rt = m;
//		}
//		else {
//			lt = m;
//			ans = m;
//		}
//
//	}
//
//	std::cout << std::fixed;
//	std::cout.precision(9);
//	std::cout << ans;
//	return 0;
//}