//
// 수학, 모듈러
//

//#include <iostream>
//
//using LL = long long;
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	LL n, m;
//	std::cin >> n >> m;
//
//	LL ans = 0;
//	for (int i = 1; i <= n; i++) {
//		LL npos = 1;
//		for (int t = i; t; t /= 10) npos *= 10;
//
//		ans = ((ans * npos)%m + i%m) % m;
//	}
//
//	std::cout << ans;
//
//	return 0;
//}