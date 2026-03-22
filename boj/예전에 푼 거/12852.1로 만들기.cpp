//// 변수 이름 + 개행
//// 논리 / 구현 명세
//// 구현은 간단히 -> 구체적으로
//// 먼저 생각하기
//
//// bfs, 트리
////
//// bfs로 탐색하면기
//// 다음에 갈 수를 인덱스로 배열에 지금의 수 넣기
//
//#include <iostream>
//#include <queue>
//#include <vector>
//
//int tree[1000001];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//	int n;
//	std::cin >> n;
//
//	std::queue <int> que;
//	que.push(n);
//	tree[n] = -1;
//
//	while (que.front() != 1) {
//		int cur = que.front();
//		que.pop();
//
//		if (cur % 3 == 0 && !tree[cur/3]) {
//			tree[cur / 3] = cur;
//			que.push(cur / 3);
//		}
//		if (cur % 2 == 0 && !tree[cur / 2]) {
//			tree[cur / 2] = cur;
//			que.push(cur / 2);
//		}
//		if (cur - 1 >= 0 && !tree[cur - 1]) {
//			tree[cur - 1] = cur;
//			que.push(cur - 1);
//		}
//	}
//
//	int cur = 1;
//	std::vector<int> st;
//	while (cur != -1) {
//		st.push_back(cur);
//		cur = tree[cur];
//	}
//	std::reverse(st.begin(), st.end());
//	std::cout << st.size() << '\n';
//	for (int i : st) {
//		std::cout << i << ' ';
//	}
//
//	return 0;
//}