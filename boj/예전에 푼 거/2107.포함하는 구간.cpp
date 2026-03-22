//
// 정렬, 이진 탐색
// 
// 시작, 끝이 담긴 배열 시작에 대해 정렬
// 끝점만 담긴 배열 정렬 (안된다, 시작점 나가 있을 수 있음)
//
// 부르트 포스, 정렬
// 
// 그냥하면 포함되는 거 못넣어
// 시작점 내림차순 정렬 -> 끝에서 부터 돌면 오름차순 해야지;;
// 
//

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using intpair = std::pair<int, int>;
//
//
//std::vector<intpair> intervals;
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 0, s, e; i < n; i++) {
//		std::cin >> s >> e;
//
//		intervals.push_back({ s, e });
//	}
//
//	//sort
//	std::sort(intervals.begin(), intervals.end());
//	
//
//	int ans = 0;
//	for (int i = n-2; i >= 0; i--) {
//		int e = intervals[i].second;
//		
//		int cnt = 0;
//		for (int k = i + 1; k < n; k++ ) {
//			if (intervals[k].second > e) continue;
//
//			cnt++;
//		}
//
//		ans = std::max(ans, cnt);
//	}
//
//
//	std::cout << ans;
//	return 0;
//}