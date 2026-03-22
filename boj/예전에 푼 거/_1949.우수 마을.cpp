// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기
//
// 
// 점점 논리가 중요해짐이 느껴진다ㅏㅏ
// 
// 트리에서 dp, dfs
// 어디서 시작하든 그 노드를 루트로 봐도 상관 X
// 무조건 모든 노드에서 적어도 1개의 우수마을이 인접해 있어야지만 최대 인구수
//  
// dp[2][n] :  dp[0][i] = i노드가 우수 마을이 아니고 i를 루트로 하는 서브트리의 인구수 최대값/
//			   dp[1][i] = i노드가 우수 마을이 아니고 i를 루트로 하는 서브트리의 인구수 최대값
//
// 
// dp[0][i] = std::max(std::max(dp[0][childs], dp[1][childs]));	//하나는 무조건 선택된 상태로 돌아야함
// 
// dp[1][i] = population[i] + std::max(dp[0][childs]);
//

//#include <iostream>
//#include <vector>
//
//std::vector<int> graph[10000];
//int dp[2][10000];
//int popu[10000];
//
//int dfs_not_select(int cur, int par);
//
//int dfs_select(int cur, int par) {
//	if (dp[1][cur]) return dp[1][cur];
//
//	int ret = 0;
//	for (const int& next : graph[cur]) {
//		if (next == par) continue;
//
//		ret += dfs_not_select( next, cur);
//	}
//
//	return dp[1][cur] = ret + popu[cur];
//}
//
//int dfs_not_select( int cur, int par) {
//	if (dp[0][cur]) return dp[0][cur];
//
//	int ret = 0;
//
//	for (const int& next : graph[cur]) {
//		if (next == par) continue;
//
//		ret += std::max(dfs_select(next, cur), dfs_not_select(next, cur));
//	}
//	
//	return dp[0][cur] = ret;
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> popu[i];
//	}
//
//	for (int i = 1, f, t; i < n; i++) {
//		std::cin >> f >> t;
//		f--, t--;
//
//		graph[f].push_back(t);
//		graph[t].push_back(f);
//	}
//
//	std::cout << std::max(dfs_select(0, 0), dfs_not_select( 0, 0));
//
//	return 0;
//}

/*
1-2-3-4-5
    /
   6

6
10 1 1 1 10 10
1 2
2 3
3 4
4 5
3 6
*/