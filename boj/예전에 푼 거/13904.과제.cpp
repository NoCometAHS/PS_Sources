//// 변수 이름 + 개행
//// 논리 / 구현 명세
//// 구현은 간단히 -> 구체적
//// 먼저 생각하기
//
////
//// 가장 큰 날 부터 보면서 pq에 현제의 날보다 큰 마감일을 가진 과제들 pq에 넣기
//// 하루마다 보면서 pq에서 하나씩 가져오기
////
//
//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using intpair = std::pair<int,int>;
//
//intpair arr[1000];
//
//int main() {
//	int n;
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> arr[i].first >> arr[i].second;
//	}
//
//	std::sort(arr, arr + n);
//
//	std::priority_queue<int> pq;
//
//	int k = n - 1;
//	int ans = 0;
//	for (int i = arr[n - 1].first; i > 0; i--) {
//		while (arr[k].first >= i) pq.push(arr[k--].second);
//
//		if (!pq.empty()) {
//			ans += pq.top();
//			pq.pop();
//		}
//	}
//
//	std::cout << ans;
//
//	return 0;
//}