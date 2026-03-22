// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기
//
// "임의의 3 점이 일직선에 존재하지 않는다"가 무슨 의미지 -> 점과 점만이 교차하는 경우를 말하는 건가?
// 
// ccw (긴 조건문 없이), 분리 집합
//
// 부분 집합이라 같은 집합에 연결하는 선분 그으면 사이클이 만들어짐

//#include <iostream>
//
//int set_tree[500000];
//
//int find_par(int cur) {
//	if (cur == set_tree[cur]) return cur;
//	else return set_tree[cur] = find_par(set_tree[cur]);
//}
//
//void union_set(int a, int b) {
//	a = find_par(a), b = find_par(b);
//
//	set_tree[a] = b;
//
//	return;
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	int n, m;
//
//	std::cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//		set_tree[i] = i;
//	}
//
//	int ans = 1;
//	for (int i = 0, a, b; i < m; i++, ans++) {
//		std::cin >> a >> b;
//
//		if (find_par(a) == find_par(b)) {
//			break;
//		}
//
//		union_set(a, b);
//	}
//
//	std::cout << (ans > m ? 0 : ans);
//
//	return 0;
//}