//
// 쌓아가는 dp
// dp[2][2000] : dp[s][i]: 판매한 책이 i권일 때 최대 비용
// 
// 장르별로 모으고 내림차순 정렬
// 
// 책을 장르마다 한번씩 dp를 도는겨
// dp[s][i] = max(dp[(s+1)%2][i-1]+ 책1권,  dp[(s+1)%2][i-2]+ 책2권....)
// 
// 11 + 14 + 13+ 6+ 16
// 

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int dp[2][2001];
//
//std::vector<int> books[10];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//
//	for (int i = 0, c, g; i < n; i++) {
//		std::cin >> c >> g;
//		books[g - 1].push_back(c);
//	}
//
//	for (int i = 0; i < 10; i++) {
//		std::sort(books[i].begin(), books[i].end(),std::greater<int>());
//	}
//
//
//	for (int genre = 0; genre < 10; genre++) {
//		int curCost = 0;
//
//		for (int i = 0; i < books[genre].size(); i++) {
//			curCost += books[genre][i] + (i + 1) * i;
//
//			for (int bookCnt = i+1; bookCnt <= m; bookCnt++){
//				dp[0][bookCnt] = std::max({ dp[0][bookCnt], dp[1][bookCnt], dp[1][bookCnt - i - 1] + curCost });
//			}
//
//			curCost -= (i + 1) * i;
//		}
//
//		//std::cout << "cur : ";
//		//for (int i = 0; i <= m; i++) {
//
//		//	std::cout << dp[0][i] << ' ';
//		//}std::cout << '\n';
//		//std::cout << "pre : ";
//		//for (int i = 0; i <= m; i++) {
//		//	
//		//	std::cout << dp[1][i] << ' ';
//		//}std::cout << "\n\n";
//
//		for (int i = 0; i <= m; i++) {
//			dp[1][i] = dp[0][i];
//		}
//
//	}
//
//	std::cout << dp[0][m];
//	return 0;
//}