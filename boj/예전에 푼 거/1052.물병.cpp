// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 쉽게 -> 명료히
// 먼저 생각하기
//

//
// 그리디, 비트연산
// 현재 물병 개수로 만들 수 있는 가장큰 물의 양을 만들어가기 -> 가장 왼쪽 1개 비트
// ans =  std::min(물병 1개로 만들었을 때 산 물병 필요 개수, 2개로, 3개로, ..., k개로)
//

//#include <iostream>
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//
//	int ltBitPos = 31;
//	while ( !((n >> ltBitPos) & 1) )ltBitPos--;
//
//	int ans = (1<<31) - 1;
//
//	while (ltBitPos >= 0 && m) {
//		ans = std::min(ans, ((n & (~(1 << ltBitPos))) ? (1 << ltBitPos) - (n & (~(1 << ltBitPos))) : 0));
//
//		n &= ~(1 << ltBitPos);
//		m--;
//
//		while (ltBitPos >= 0 && !((n >> ltBitPos) & 1))ltBitPos--;
//	}
//
//	std::cout << ans;
//	return 0;
//}