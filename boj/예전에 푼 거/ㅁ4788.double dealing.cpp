//// 변수 이름 + 개행
//// 논리 / 구현 명세
//// 구현은 쉽게 -> 명료히
//// 먼저 생각하기
//
////
//// 시뮬?
//// 
//// 수학적으로 새는 방법이 있나???
////  
//// 일단 시뮬만들어 봐야지 (불가능, 느림) ex) 800 250
//// 
////
//
//#include <iostream>
//
//using LL = long long;
//
//int cards[2][800];
//
//void shuffle(int n, int m, int from, int to) {
//	int temp[800], top = 0;
//	int cardIdx = 0;
//
//	for (int i = 0; i < m; i++) {
//		top = 0;
//		for (int k = i; k < n; k += m) {
//			temp[top++] = cards[from][k];
//		}
//
//		while (top > 0) {
//			cards[to][cardIdx++] = temp[--top];
//		}
//	}
//
//	return;
//}
//
//bool is_continuous(int n, int from) {
//	for (int i = 0; i < n; i++) {
//		if (cards[from][i] != i + 1) return false;
//	}
//
//	return true;
//}
//
//int main() {
//	int n, m;
//
//	std::cin >> n >> m;
//
//	while (n != 0) {
//		for (int i = 0; i < n; i++) {
//			cards[0][i] = i + 1;
//		}
//
//		LL ans = 1;
//		
//		for (shuffle(n, m, ans - 1, ans); !is_continuous(n, ans % 2); shuffle(n, m, ans % 2, (ans + 1) % 2), ans++) {
//
//		};
//
//		std::cout << ans;
//		
//		std::cin >> n >> m; 
//	}
//
//	return 0;
//}
//
//
