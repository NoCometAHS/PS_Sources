// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 교차 판단은 ccw로 간단히 X
// 위에서 부터 교차하지 않게 전선 놓는다고 할 때, 
// // 겹친다면 자기 위로 연속하게 겹침 
// // b로 연결된 부분에서 바로 위 봐보면 전부와 겹치는지 확인 가능
// 
// 쌓아가는 dp + 이진 탐색
// a에 대해서 오름차 정렬
// a에서 위부터 아래로 하나씩 연결해 봄
// {int b, int c}dp[n] : 가로등 b에서 b 번째로 연결된 선이 마지막으로 쓰였을때 모든 선이 교차하지 않고 연결된 최대 갯수
// (X / (1, 10) , (2, 2), (3, 3), (4, 4), (5, 11))
//
// a에 대해서 오름차 정렬
// a에서 위부터 아래로 하나씩 연결해 봄
// dp[i] : i개 만큼 연결 했을 때 b의 값이 작은 것을 저장 -> 알아서 오름차순 정렬 됨 따라서 이진 탐색 가능
// tree로 누가 세트인지 확인 (시바 트리로 했는데 뭔가 무한반복되나바)

//#include <iostream>
//#include <algorithm>
//
//using intpair = std::pair<int, int>;
//
//intpair lines[100001];
//int dp[100001];
//intpair ans[100001];
//int bLineNum[100001];
//bool chk[100001];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//
//	for (int i = 1; i <= n; i++) {
//		std::cin >> lines[i].first>> lines[i].second;
//	}
//
//	std::sort(lines+1, lines + n + 1);
//
//	int maxCnt = 0, maxCntIdx = -1;
//
//	for (int i = 1; i <= n; i++) {
//		if (dp[maxCnt] < lines[i].second) {
//			maxCntIdx = i;
//
//			dp[++maxCnt] = lines[i].second;
//			ans[i] = { maxCnt, lines[i].first };
//		}
//		else {
//			int* pos = std::lower_bound(dp, dp + maxCnt, lines[i].second);
//
//			int cnt = pos - dp;
//			if (cnt > maxCnt) {
//				maxCnt = cnt;
//				maxCntIdx = i;
//			}
//
//			ans[i] = { cnt, lines[i].first };
//			dp[cnt] = lines[i].second;
//		}
//	}
//
//	std::cout << n - maxCnt << '\n';
//
//	
//	for (int i = n; i > 0; i--) {
//		if (ans[i].first != maxCnt) continue;
//
//		maxCnt--;
//		chk[ans[i].second] = true;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		if (chk[lines[i].first]) continue;
//		std::cout << lines[i].first << '\n';
//	}
//
//
//	return 0;
//}