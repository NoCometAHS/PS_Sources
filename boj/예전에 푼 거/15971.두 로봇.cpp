// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적으로
// 먼저 생각하기

//
// 그래프, dfs, 그리디
// 
// 일단 두 노드를 이어주는 통로의 비용들을 나열 (통로는 하나로 유일)
// a, b, c, d...
// 
// 여기서 비용 하나빼고 전부다 더한 값이 만나는데 드는 비용
// 따라서 가장 큰 비용 빼고 더하는 값이 최소값
// 
// dfs로 통로 찾고 최대값 빼고 다 더하기
//
//
//#include <iostream>
//#include <vector>
//
//using intpair = std::pair<int, int>;
//
//std::vector<intpair> graph[100100];
//bool chk[100100];
//
//int st, en;
//
//int dfs(int cur) {
//	static std::vector<int> costs;
//
//	if (cur == en) {
//		int max = 0, sum = 0;
//		for (const int& i : costs) {
//			sum += i;
//			max = std::max(max, i);
//		}
//
//		return sum - max;
//	}
//
//	int res = -1;
//
//	for (const intpair& next : graph[cur]) {
//		if (chk[next.second]) continue;
//
//		chk[next.second] = true;
//		costs.push_back(next.first);
//		
//		res = dfs(next.second);
//		if (res != -1) break;
//
//		costs.pop_back();
//	}
//
//	return res;
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n >> st >> en;
//
//	for (int i = 1, from, to, c; i < n; i++) {
//		std::cin >> from >> to >> c;
//
//		graph[from].push_back({ c, to });
//		graph[to].push_back({ c, from });
//	}
//
//	chk[st] = true;
//	std::cout << dfs(st);
//
//	return 0;
//}
