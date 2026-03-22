// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// dp, dfs
// {int} dp[i] : i~k까지의 문자열은 팰린드롬의 길이?
//
// 모든 팰린드롬 구하기
// dfs로 부르트포스
// 대충 최악 2500*2500 + 2500^2500 (E Va) dfs 불가능 아닌가?
//
// dp[i] : i에서 n-1까지 문자일때 최소의 팰린드롬 갯수
// 
// assavccvassaoppoassavccv
// 
// dfs랑 섞는 dp 
// 
//#include <iostream>
//
//bool dp[2500][2500];
//int cnt[2500];
//char str[2501]; int n;
//
//int dfs(int cur) {
//	if (cur >= n) return 0;
//	if (cnt[cur]) return cnt[cur];
//
//	int min = 1e9;
//	for (int i = cur; i < n; i++) {
//		if (!dp[cur][i]) continue;
//
//		min = std::min(min, dfs(i + 1) + 1);
//	}
//
//	return cnt[cur] = min;
//}
//
//int main() {
//	while ((str[n] = getchar()) != '\n') { dp[n][n] = true; n++; };
//	str[n] = 0;
//	cnt[n - 1] = 1;
//
//	for (int len = 1; len < n; len++) {
//		for (int lf = 0; lf < n - len; lf++) {
//			if (str[lf] != str[lf + len]) continue;
//
//			dp[lf][lf + len] = dp[lf + 1][lf + len - 1] || len == 1;
//		}
//	}
//
//	std::cout << dfs(0);
//	return 0;
//}