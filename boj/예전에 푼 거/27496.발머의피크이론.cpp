// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 2포인터가 아니라 슬라이딩 윈도우라고 부른데
// 129 ~ 138사이 유지하도록 움직임

//#include <iostream>
//
//int alcohol[1000001];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cout.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//
//	for (int i = 1; i <= n; i++) {
//		std::cin >> alcohol[i];
//	}
//
//	int cur = 0, ans = 0;
//	for (int f = 0, b = 1; b <= n; b++) {
//		if (b > m) f++;
//		cur -= alcohol[f];
//
//		cur += alcohol[b];
//		
//		if (cur >= 129 && cur <= 138) ans++;
//	}
//
//	std::cout << ans;
//	return 0;
//}