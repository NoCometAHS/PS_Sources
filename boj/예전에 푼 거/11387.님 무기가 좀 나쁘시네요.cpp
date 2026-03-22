// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

//#include <iostream>
//
//double status[2][5];
//double weapons[2][5];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	for (int i = 0; i < 2; i++) {
//		for (int k = 0; k < 5; k++) {
//			std::cin >> status[i][k];
//		}
//	}
//
//	for (int i = 0; i < 2; i++) {
//		for (int k = 0; k < 5; k++) {
//			std::cin >> weapons[i][k];
//		}
//	}
//
//	double basic[2], changed[2];
//
//	for (int i = 0; i < 2; i++) {
//		basic[i] = status[i][0] * (1 + status[i][1] / 100) * ((1 - std::min(status[i][2] / 100, 1.0)) + std::min(status[i][2]/100, 1.0) * status[i][3]/100) * (1 + status[i][4]/100);
//	}
//
//	for (int i = 0; i < 2; i++) {
//		for (int k = 0; k < 5; k++) {
//			status[i][k] += weapons[(i+1)%2][k] - weapons[i][k];
//		}
//	}
//
//	for (int i = 0; i < 2; i++) {
//		changed[i] = status[i][0] * (1 + status[i][1] / 100) * ((1 - std::min(status[i][2] / 100, 1.0)) + std::min(status[i][2] / 100, 1.0) * status[i][3] / 100) * (1 + status[i][4] / 100);
//	}
//
//	for (int i = 0; i < 2; i++) {
//		std::cout << (basic[i] == changed[i] ? '0' : (basic[i] < changed[i] ? '+' : '-')) << '\n';
//	}
//
//	return 0;
//}