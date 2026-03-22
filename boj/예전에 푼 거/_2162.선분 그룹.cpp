// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// ccw, union&find
//
// ccw로 선분 교차 검사
// 교차하면 같은 집합으로
//

//#include <iostream>
//#include <algorithm>
//
//using LL = long long;
//
//LL lines[3000][4];
//int tree[3000];
//int cnt[3000];
//
//void point_swap(LL* line) {
//	std::swap(line[0], line[2]);
//	std::swap(line[1], line[3]);
//	
//	return;
//}
//
//int find_par(int cur) {
//	if (tree[cur] == cur) return cur;
//	else return tree[cur] = find_par(tree[cur]);
//}
//
//void union_set(int a, int b) {
//	a = find_par(a), b = find_par(b);
//
//	if (a == b) return;
//
//	tree[a] = b;
//	cnt[b] += cnt[a];
//
//	return;
//}
//
//LL ccw(LL* line, LL* point) {
//	return line[0] * line[3] + line[2] * point[1] + point[0] * line[1] - line[2] * line[1] - point[0] * line[3] - line[0] * point[1];
//}
//
//bool crossed(LL* line1, LL* line2) {
//	LL res1 = ccw(line1, line2) * ccw(line1, line2+2), res2 = ccw(line2, line1) * ccw(line2, line1+2);
//
//	if (res1 > 0 || res2 > 0) {
//		return false;
//	}
//	else if (!res1 && !res2){
//		if (line1[0] > line1[2]) {
//			point_swap(line1);
//		}
//		if (line2[0] > line2[2]) {
//			point_swap(line2);
//		}
//
//		if (line2[2] < line1[0] || line1[2] < line2[0]) {
//			return false;
//		}
//
//		if (line1[1] > line1[3]) {
//			point_swap(line1);
//		}
//		if (line2[1] > line2[3]) {
//			point_swap(line2);
//		}
//
//		if (line2[3] < line1[1] || line1[3] < line2[1]) {
//			return false;
//		}
//	}
//
//	return true;
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		tree[i] = i;
//		cnt[i] = 1;
//
//		for (int k = 0; k < 4; k++) {
//			std::cin >> lines[i][k];
//		}
//	}
//
//
//	for (int i = 0; i < n - 1; i++) {
//		for (int k = i + 1; k < n; k++) {
//			if (!crossed(lines[i], lines[k])) continue;
//
//			if (find_par(i) == find_par(k)) continue;
//
//			union_set(i, k);
//		}
//	}
//
//
//	bool chk[3000] = { false, };
//	int grpCnt = 0, maxCnt = 0;
//	for (int i = 0; i < n; i++) {
//		int par = find_par(i);
//		if (chk[par]) continue;
//
//		grpCnt++;
//		chk[par] = true;
//		maxCnt = std::max(maxCnt, cnt[par]);
//	}
//
//	std::cout << grpCnt << '\n' << maxCnt;
//
//	return 0;
//}