//
// 구현, 누적합
//
//

//#include <iostream>
//#include <vector>
//
//using intpair = std::pair<int, int>;
//
//int map[3004][3004];
//int energy[4]; //u d l r
//char dirChar[5] = "UDLR";
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 2; i <= n + 1; i++) {
//		for (int k = 2; k <= n + 1; k++) {
//			std::cin >> map[i][k];
//			map[i][k] += map[i][k - 1] + map[i - 1][k] - map[i - 1][k - 1];
//		}
//	}
//
//	intpair LU = { n / 2+1, n / 2+1 }, RD = { n / 2 + 2, n / 2 + 2 };
//
//	int ans = 0;
//	std::vector<char> ansStr;
//	while (true) {
//		energy[0] = map[LU.second - 1][RD.first] - map[LU.second - 2][RD.first] - map[LU.second - 1][LU.first - 1] + map[LU.second - 2][LU.first - 1];
//		energy[1] = map[RD.second + 1][RD.first] - map[RD.second][RD.first] - map[RD.second + 1][LU.first - 1] + map[RD.second][LU.first - 1];
//		energy[2] = map[RD.second][LU.first - 1] - map[RD.second][LU.first - 2] - map[LU.second - 1][LU.first - 1] + map[LU.second - 1][LU.first - 2];
//		energy[3] = map[RD.second][RD.first + 1] - map[RD.second][RD.first] - map[LU.second - 1][RD.first + 1] + map[LU.second - 1][RD.first];
//
//		int maxDir, max = 0;
//		for (int i = 0; i < 4; i++) {
//			if (max < energy[i]) {
//				max = energy[i];
//				maxDir = i;
//			}
//		}
//
//		if (max == 0) break;
//
//		ans += max;
//		ansStr.push_back(dirChar[maxDir]);
//
//		switch (maxDir) {
//		case 0:
//			LU.second--;
//			break;
//		case 1:
//			RD.second++;
//			break;
//		case 2:
//			LU.first--;
//			break;
//		case 3:
//			RD.first++;
//			break;
//		}
//	}
//
//	std::cout << ans << '\n';
//	for (const char& ch : ansStr) {
//		std::cout << ch;
//	}
//
//	return 0;
//}