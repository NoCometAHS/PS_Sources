// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 쉽게 -> 명료히
// 먼저 생각하기

//
// union & find
//

//#include <iostream>
//
//int setTree[1001];
//
//int find_par(int cur) {
//	if (cur == setTree[cur]) return cur;
//	else return setTree[cur] = find_par(setTree[cur]);
//}
//
//bool union_set(int a, int b) {
//	a = find_par(a), b = find_par(b);
//
//	if (a == b) return false;
//
//	setTree[b] = a;
//
//	return true;
//}
//
//int main() {
//	int tc;
//	std::cin >> tc;
//
//	while(tc--) {
//		std::ios::sync_with_stdio(false);
//		std::cin.tie(nullptr);
//
//		int n;
//		std::cin >> n;
//
//
//		for (int i = 1; i <= n; i++) {
//			setTree[i] = i;
//		}
//
//		int cnt = n;
//		for (int i = 1, num; i <= n; i++) {
//			std::cin >> num;
//
//			if (union_set(i, num)) {
//				cnt--;
//			}
//		}
//
//		std::cout << cnt << '\n';
//	}
//	return 0;
//}