// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 다익스트라 + tree
//
// 다익스트라로 탐색하는데, 도착한 지점에서 어디서 왔는지를 부모로 만듦

//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using intpair = std::pair<int, int>;
//
//struct DIR {
//	int f;
//	int t;
//	int c;
//	DIR(int f, int t, int c) : f(f), t(t), c(c){}
//	bool operator<(const DIR& a)const {
//		return a.c < c;
//	}
//};
//
//int n, m;
//std::vector<intpair> graph[20];
//int cost[50];
//int tree[50];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	int t;
//	std::cin >> t;
//
//	for (int tc = 1; tc <= t; tc++) {
//		std::cin >> m >> n;
//
//		for (int i = 0; i < n; i++) {
//			tree[i] = -1;
//			cost[i] = 1e9;
//			graph[i].clear();
//		}
//
//		for (int i = 0, f, t, c; i < m; i++) {
//			std::cin >> f >> t >> c;
//			graph[f].push_back({ c, t });
//			graph[t].push_back({ c, f });
//		}
//
//
//		std::priority_queue<DIR> pq;
//		pq.push({ -1,0,0 });
//		cost[0] = 0;
//
//		while (!pq.empty()) {
//			DIR cur = pq.top();
//			pq.pop();
//
//			if (cur.c > cost[cur.t]) continue;
//
//			tree[cur.t] = cur.f;
//
//			for (intpair next : graph[cur.t]) {
//				int nxtCost = next.first + cur.c;
//
//				if (nxtCost >= cost[next.second]) continue;
//
//				cost[next.second] = nxtCost;
//				pq.push({ cur.t, next.second, nxtCost });
//			}
//		}
//
//		std::cout << "Case #" << tc << ": ";
//		if (cost[n - 1] == 1e9) {
//			std::cout << "-1\n";
//		}
//		else {
//			std::vector<int> st;
//			int cur = n - 1;
//			
//			while (cur != -1) {
//				st.push_back(cur);
//				cur = tree[cur];
//			}
//
//			std::reverse(st.begin(), st.end());
//
//			for (int i : st) {
//				std::cout << i << ' ';
//			}
//			std::cout << '\n';
//		}
//
//	}
//	return 0;
//}