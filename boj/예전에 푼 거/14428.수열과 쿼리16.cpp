//// 세그 트리
//
//#include <iostream>
//#include <algorithm>
//
//int segTree[2 << 17];
//int arr[100001] = {2000000000, };
//
//void init_tree(int lt, int rt, int node = 1) {
//	if (lt == rt) {
//		segTree[node] = lt;
//		return;
//	}
//
//	int m = (lt + rt) / 2;
//	init_tree(lt, m, node * 2);
//	init_tree(m + 1, rt, node * 2 + 1);
//
//	segTree[node] = (arr[segTree[node * 2]] <= arr[segTree[node * 2 + 1]] ? segTree[node * 2] : segTree[node * 2 + 1]);
//	return;
//}
//
//void change_num(int idx, int n, int lt, int rt, int node = 1) {
//	if (idx < lt || rt < idx) return;
//
//	if (lt == rt) {
//		arr[lt] = n;
//		return;
//	}
//
//	int m = (lt + rt) / 2;
//	change_num(idx, n, lt, m, node * 2);
//	change_num(idx, n, m + 1, rt, node * 2 + 1);
//
//	segTree[node] = (arr[segTree[node * 2]] <= arr[segTree[node * 2 + 1]] ? segTree[node * 2] : segTree[node * 2 + 1]);
//
//	return;
//}
//
//
//int find_min_idx(int fr, int en, int lt, int rt, int node = 1) {
//	if (fr > rt || en < lt) return 0;
//	if (fr <= lt && rt <= en) return segTree[node];
//	
//	int m = (lt + rt) / 2;
//	int ret1 = find_min_idx(fr, en, lt, m, node * 2), ret2 = find_min_idx(fr, en, m + 1, rt, node * 2 + 1);
//	return (arr[ret1] <= arr[ret2] ? ret1 : ret2);
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		std::cin >> arr[i];
//	}
//
//	init_tree(1, n);
//
//	int m;
//	std::cin >> m;
//	
//	int query;
//	while (m--) {
//		std::cin >> query;
//
//		if (query == 1) {
//			int idx, num;
//			std::cin >> idx >> num;
//			change_num(idx, num, 1, n);
//		}
//		else {
//			int lt, rt;
//			std::cin >> lt >> rt;
//			std::cout << find_min_idx(lt, rt, 1, n) << '\n';
//		}
//	}
//
//	return 0;
//}