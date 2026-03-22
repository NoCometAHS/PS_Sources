// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기


// 스위핑
//
// 먼저 선분들 시작점, 끝점 순으로 오름차정렬
// 맨 처음 점에서 시작, 끝점이 Line이 끝나는 위치보다 작은거 다 넣어
// 오른쪽으로 점 하나씩 움직이면서 빼고 더하고ㄱㄱ


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//
//using intpair = std::pair<int, int>;
//
//intpair lines[100000];
//std::vector<int> points;
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> lines[i].first >> lines[i].second;
//		if (lines[i].first > lines[i].second) std::swap(lines[i].first, lines[i].second);
//		points.push_back(lines[i].first);
//	}
//
//	std::sort(points.begin(), points.end());
//	points.push_back(1e9);
//
//	std::sort(lines, lines + n, [](const intpair& a, const intpair& b) {return (a.second == b.second ? a.first < b.first : a.second < b.second); });
//
//	std::priority_queue<intpair, std::vector<intpair>, bool (*)(const intpair&, const intpair&)> pq([](const intpair& a, const intpair& b) { return a.first > b.first; });
//
//	int frIdx = 0 ,fr = points[0], enIdx = 0, en, d;
//	std::cin >> d;
//	en = fr + d;
//
//	int ans = 0;
//	while (fr != 1e9) {
//		for (; enIdx < n && lines[enIdx].second <= en; enIdx++) {
//			pq.push(lines[enIdx]);
//		}
//
//		while (!pq.empty() && pq.top().first < fr) pq.pop();
//
//		ans = (ans > pq.size() ? ans : pq.size());
//
//		for (; fr == points[frIdx]; frIdx++);
//
//		en = points[frIdx] + d;
//		fr = points[frIdx];
//	}
//
//	std::cout << ans;
//
//	return 0;
//}
