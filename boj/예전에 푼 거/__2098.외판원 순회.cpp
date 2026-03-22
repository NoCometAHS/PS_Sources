// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 다익스트라, 브루트 포스
// n개 노드에서 각각 시작
// 시작하는 노드와 연결된 노드로 시작으로 다익스트라로 뻗어감 (어디 지나왔는지 표시해가며)
// 와봤던 곳이면 지나온 곳 합쳐서 전부다 간 것이 되면 종료, 아님 넘어감 갱신 못 함
//
// pq 자료형 : 지나온 노드 표시(비트), 어디서 뻗어온 넘버링(비트), 간격 (x, 어디서 어떻게 합쳐야 하는 지 애매)

// dp, 비트 마스킹, 브루트 포스
// 
//

//#include <iostream>
//
//int dp[16][1 << 17];	//dp[cur][visited] : 방문하지 않았던 노드 갔을 때 최소 비용
//int graph[16][16], n;
//int finished;
//
//int dfs(int cur = 0, int visited = 1) {
//	if (dp[cur][visited]) return dp[cur][visited];
//
//	int min = 2e9;
//	for (int i = 0; i < n; i++) {
//		if (!graph[cur][i] || visited & (1<<i) ) continue;
//
//		int t = dfs(i, visited | (1 << i)) + graph[cur][i];
//
//		min = std::min(min, t);
//	}
//
//	return dp[cur][visited] = min;
//}
//
//int main() {
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		finished |= (1 << i);
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int k = 0; k < n; k++) {
//			std::cin >> graph[i][k];
//		}
//		dp[i][finished] = graph[i][0];
//	}
//
//	std::cout << dfs();
//
//	return 0;
//}