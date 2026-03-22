// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

//
// 구현
// 조수가 p가지를 1개라도 가지고 있으면 그 조수는 결과로 p가지를 만듬
// w가지만 있어야 w가지 만들 수 있음
// 
// 조수중 누구 1명이라도 w가지가 있으면 답은 w
// 아니면 p
//

//#include <iostream>
//
//bool gajiSort[1000];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	char ch;
//	for (int i = 0; i < n; i++) {
//		std::cin >> ch;
//		gajiSort[i] = ch == 'W';
//	}
//
//	int m, p;
//	std::cin >> m >> p;
//
//	bool ans = false;
//
//	for (int i = 0; i < m; i++) {
//		bool res = true;
//		for (int k = 0, sort; k < p; k++) {
//			std::cin >> sort;
//			res &= gajiSort[sort - 1];
//		}
//
//		ans |= res;
//	}
//
//	std::cout << (ans ? "W" : "P");
//
//	return 0;
//}