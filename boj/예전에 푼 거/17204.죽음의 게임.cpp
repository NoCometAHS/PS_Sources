//
// ±×·¡ÇÁ Å½»ö
//

//#include <iostream>
//
//int dir[150];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> dir[i];
//	}
//
//	bool chk[150] = { false, };
//	int cur = 0, ans = -1, cnt = 0;;
//	while (!chk[cur]) {
//		if (cur == m) {
//			ans = cnt;
//			break;
//		}
//
//		chk[cur] = true;
//		cnt++;
//		cur = dir[cur];
//	}
//
//	std::cout << ans;
// return 0;
//}