//
// 진짜 그냥 철수가 낸 카드보다 큰 수중 가장 작은거 출력하고 카드 배열에서 빼면 됨
// 
// linked list, 이진 탐색
// (x, "???: list는 빠가다", list에서 lower_bound는 선형시간걸림)
// 
// 세그 트리
// 1 - N까지 범위의 최소값 세그 트리 만듬
// [입력 받은 수+1, n]까지 중에서 최소값 찾는 쿼리
// 수 바꾸는 쿼리
//

//#include <iostream>
//#include <algorithm>
//
//int segTree[2 << 22];
//bool arr[4400400];
//
//void init(int lt, int rt, int node = 1) {
//	if (lt == rt) {
//		segTree[node] = (arr[lt] ? lt : 1e9);
//		return;
//	}
//
//	int m = (lt + rt) / 2;
//	init(lt, m, node * 2);
//	init(m + 1, rt, node * 2 + 1);
//	segTree[node] = std::min(segTree[node * 2], segTree[node * 2 + 1]);
//
//	return;
//}
//
//void toggle_num(int idx, int lt, int rt, int node = 1) {
//	if (idx < lt || idx > rt) return;
//
//	if (lt == rt) {
//		arr[lt] = !arr[lt];
//		segTree[node] = (arr[lt] ? lt : 1e9);
//		return;
//	}
//
//	int m = (lt + rt) / 2;
//	toggle_num(idx, lt, m, node * 2);
//	toggle_num(idx, m + 1, rt, node * 2 + 1);
//	segTree[node] = std::min(segTree[node * 2], segTree[node * 2 + 1]);
//
//	return;
//}
//
//int find_min(int st, int en, int lt, int rt, int node = 1) {
//	if (st > rt || en < lt) return 1e9;
//	if (st <= lt && rt <= en) return segTree[node];
//	
//	int m = (lt + rt) / 2;
//
//	return std::min(find_min(st, en, lt, m, node * 2), find_min(st, en, m + 1, rt, node * 2 + 1));
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m, t;
//	std::cin >> n >> m >> t;
//
//	
//	for (int i = 0, num; i < m; i++) {
//		std::cin >> num;
//		arr[num] = true;
//	}
//
//	init(0, n);
//
//	for (int i = 0, num; i < t; i++) {
//		std::cin >> num;
//
//		int res = find_min(num + 1, n, 0, n);
//		std::cout << res << '\n';
//
//		toggle_num(res, 0, n);
//	}
//
//
//	return 0;
//}