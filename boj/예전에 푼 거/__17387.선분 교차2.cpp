//// 변수 이름 + 개행
//// 논리 / 구현 명세
//// 구현은 간단히 -> 구체적
//// 먼저 생각하기
//
//// 수학?, 많은 분기
//// 
//// 선분의 점들 비교해서 첫번째 점이 x값이 작게 정렬
//// 1.점 x위치가 작은 선분이 첫번째 선분으로
//// // 2.선분의 1.점의 x 1.선분의 2.점의 x보다 크면 교차하지 않음! 
////
//// // 만약 1.선분의 1.점의 y 값이 2.선분의 1.점의 y값보다 작으면
//// // // 만약
////
//// 아니다 못한다. 안되는 경우랑 되는 경우 조건 겹치는 거 있음
//
//// 기하
//// ㅅㅂ 진짜 ccw네 ㅅㅄㅂ
//// a c e a
//// b d f b
//// ad + cf + eb - cb - ed - af
//// tqtqtqtqtqtqtqtqt 구하는 법 대충 보고 했다가 ㅅㅂ 몇시간 걸린거야 ㄻㄴ리ㅏㅓㅁㄴ이라ㅜ;ㄷㄱㅍㅎ
//
//#include <iostream>
//
//using LL = long long;
//
//LL L1[4], L2[4];
//
//LL ccw(LL* b, LL* u, LL* v) {
//	LL res = b[0] * u[1] + u[0] * v[1] + v[0] * b[1] - u[0] * b[1] - v[0] * u[1] - b[0] * v[1];
//	return (res == 0 ? 0 : (res < 0 ? 1 : -1));
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	while (true) {
//		for (int i = 0; i < 4; i++) {
//			std::cin >> L1[i];
//		}
//
//		for (int i = 0; i < 4; i++) {
//			std::cin >> L2[i];
//		}
//
//		if (L1[0] > L1[2]) {
//			std::swap(L1[0], L1[2]);
//			std::swap(L1[1], L1[3]);
//		}
//		if (L2[0] > L2[2]) {
//			std::swap(L2[0], L2[2]);
//			std::swap(L2[1], L2[3]);
//		}
//
//
//		LL res1 = ccw(L1, L1 + 2, L2) * ccw(L1, L1 + 2, L2 + 2), res2 = ccw(L2, L2 + 2, L1) * ccw(L2, L2 + 2, L1 + 2);
//
//		if (res1 > 0 || res2 > 0) {
//			std::cout << 0;
//		}
//		else if (!res1 && !res2) {
//			if (L1[0] > L2[2] || L1[2] < L2[0]) {
//				std::cout << 0;
//			}
//			else {
//				if (L1[1] > L1[3]) {
//					std::swap(L1[1], L1[3]);
//				}
//				if (L2[1] > L2[3]) {
//					std::swap(L2[1], L2[3]);
//				}
//
//				if (L1[1] > L2[3] || L1[3] < L2[1]) {
//					std::cout << 0;
//				}
//				else {
//					std::cout << 1;
//				}
//			}
//		}
//		else {
//			std::cout << 1;
//		}
//	}
//	return 0;
//}