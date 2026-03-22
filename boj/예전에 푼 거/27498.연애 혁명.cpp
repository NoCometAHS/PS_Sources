// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// mst
// 성사된 관계는 미리 연결하고 아닌 것만 mst
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//struct DIR {
//	int f;
//	int t;
//	int c;
//
//	DIR(int f, int t, int c) : f(f), t(t), c(c) {}
//	bool operator< (const DIR& a) const {
//		return c > a.c;
//	}
//};
//
//int setTree[10000];
//
//int find_par(int cur) {
//	if (setTree[cur] == cur) return cur;
//	else return setTree[cur] = find_par(setTree[cur]);
//}
//
//bool union_set(int a, int b) {
//	a = find_par(a), b = find_par(b);
//
//	if (a == b)
//		return false;
//
//	setTree[b] = a;
//
//	return true;
//}
//
//std::vector<DIR> dirs;
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//		setTree[i] = i;
//	}
//
//	int ans = 0, love = 0;
//	for (int i = 0, f, t, c, made; i < m; i++) {
//		std::cin >> f >> t >> c >> made;
//		
//		love += c;
//
//		if (made) {
//			ans += c;
//			union_set(f-1, t-1);
//		}
//		else {
//			dirs.push_back({ f-1, t-1, c });
//		}
//	}
//
//	std::sort(dirs.begin(), dirs.end());
//
//	for (const DIR& dir : dirs) {
//		if (!union_set(dir.f, dir.t)) continue;
//
//		ans += dir.c;
//	}
//
//	std::cout << love - ans;
//	return 0;
//}