//#include <iostream>
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	int Y = 0, M = 0;
//	for (int i = 0, num; i < n; i++) {
//		std::cin >> num;
//
//		Y += (num / 30 + 1)* 10;
//		M += (num / 60 + 1)* 15;
//	}
//	std::cout << Y << ' ' << M << '\n';
//	if (M <= Y) {
//		std::cout << "M ";
//	}
//	if (Y <= M) {
//		std::cout << "Y ";
//	}
//	std::cout << std::min(Y, M);
//
//	return 0;
//}