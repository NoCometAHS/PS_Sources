//
// 그리디
// 고양이 1마리만 생성마법하고 나머지 전부 모든 고양이 복제하는 마법이 좋음
// 이제 모든 고양이 복제했을 때 목표 고양이 수를 넘는다면 안넘게 복제하면 그만
//
//
//#include <iostream>
//
//using LL = long long;
//
//int main() {
//	LL n;
//	std::cin >> n;
//
//	if (!n) {
//		std::cout << 0;
//		return 0;
//	}
//
//	LL ans = 1, cur = 1;
//
//	while (cur < n) {
//		cur <<= 1;
//		ans++;
//	}
//	std::cout << ans;
//
//	return 0;
//}