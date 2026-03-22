// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// mst
// 그래프 mst로 만들기
// 가장 가중치 큰 간선 없애기

//#include <iostream>
//#include <algorithm>
//
//struct DIR {
//	int f;
//	int t;
//	int c;
//
//	DIR(int f = 0, int t = 0, int c = 0) : f(f), t(t), c(c){}
//	bool operator< (const DIR& a) const {
//		return c < a.c;
//	}
//};
//
//int tree[100000];
//
//int find_par(int cur) {
//	if (cur == tree[cur]) return cur;
//	else return tree[cur] = find_par(tree[cur]);
//}
//
//void union_set(int a, int b) {
//	a = find_par(a), b = find_par(b);
//
//	tree[a] = b;
//	return;
//}
//
//DIR dir[1000000];
//
//int main() {
//	int n, m;
//	std::cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//		tree[i] = i;
//	}
//
//	for (int i = 0; i < m; i++) {
//		std::cin >> dir[i].f >> dir[i].t >> dir[i].c;
//	}
//
//	std::sort(dir, dir + m);
//
//	int res = 0, max = 1; 
//	for (int i = 0; i < m; i++) {
//		if (find_par(dir[i].f) == find_par(dir[i].t)) continue;
//		
//		union_set(dir[i].f, dir[i].t);
//		res += dir[i].c;
//		max = std::max(max, dir[i].c);
//	}
//
//	std::cout << res - max;
//
//	return 0;
//}