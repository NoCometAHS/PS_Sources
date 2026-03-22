//
// 그리디
// 
// 각 노드에서부모가 몇개인지만 저장
// 각 부모 개수에서 d를 빼고 d로 나눈 몫을 ans에 더하기
//
//
//#include <iostream>
//#include <map>
//
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, d;
//	std::cin >> n >> d;
//
//	std::map<int, int> parCnt;
//
//	for (int i = 0, child; i < n; i++) {
//		std::cin >> child;
//
//		parCnt[child]++;
//	}
//
//	int ans = 0;
//	for (const std::pair<int, int>& cnt : parCnt) {
//		if (cnt.second - d <= 0) continue;
//		ans += (cnt.second-d) / (d - 1) + ((cnt.second - d) % (d - 1) != 0);
//	}
//
//	std::cout << ans;
//
//	return 0;
//}