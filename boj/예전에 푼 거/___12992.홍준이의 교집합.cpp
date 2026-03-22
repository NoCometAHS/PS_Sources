// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

//
// 정렬, 재귀, 피보나치식 dp
// 
// lt, rt순으로 오름차순 정렬
// 
// 선택한 구간의 rt보다 lt가 초과인 모든 구간은 볼 필요 없음, 즉 공집합이 하나라도 만들어지면 볼 필요 없음
//
// 구간을 하나 정하고 다음 구간을 정한다고 하자,
// 그 다른 구간은 처음 구간과 오른쪽에 걸치거나 포함되어있다. (왼쪽에서 걸친 건 전번째 실행에서 처리 했음) (??먼지 모르겠)
// 
// 
// 2107.포함하는 구간 처럼 하면 되지 않을까?
// 
// 난 겹치게 된것만 관심 있어, 떨어지게 된 것끼리는 절대 답에 영향을 주지 않아
// 
// lt, rt순으로 오름차순 정렬
//
// vector<{int, int}> dp[1] (x)
// 
// 스위핑
// ㅄ이라니;;; 문제가 ㅈㄴ 어렵더만
//
//
// 더블 카운팅, 모듈러에서 곱셈의 역원, 조합, pq, 좌표 압축
//
// a^p-1 = 1 (mod p)
// a * a^p-2 = 1 (mod p)
// 
// 모든 교집합의 경우의 길이 합 == (한 구간 길이 * 그 구간을 포함하는 가지의 교집합 개수)의 합
// 한 점씩 볼꺼임, 몇가지 교집합 개수 생기는 지
// 
// 
// 구간 시점에 대해 오름차순 정렬
// 한 점보다 시작 점이 작거나 같은 구간의 끝 점을 pq에 넣음.
// 끝 점이 한 점보다 작다면 pq에서 뺌 
//

//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//
//#define PRIME 1000000007
//
//using LL = long long;
//using intpair = std::pair<int, int>;
//
//LL facto[200200];
//intpair intervals[200200];
//std::vector<int> points;
//
//LL myPow(LL a, int b) {
//	if (b == 0) return 1;
//	if (b == 1) return a;
//
//	LL ret = myPow(a, b / 2);
//	ret = (ret * ret) % PRIME;
//
//	if (b % 2) {
//		return (ret * a) % PRIME;
//	}
//	else {
//		return ret;
//	}
//}
//
//LL comb(int n, int m) {
//	if (n < m) return 0;
//	if (m == 0) return 1;
//
//	return (facto[n] * myPow((facto[m] * facto[n - m]) % PRIME, PRIME - 2))%PRIME;
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	
//	points.reserve(400400);
//
//	facto[0] = 1;
//	for (int i = 1; i <= 200000; i++) {
//		facto[i] = (facto[i-1] * i)%PRIME;
//	}
//
//	int n, m;
//	std::cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		std::cin >> intervals[i].first >> intervals[i].second;
//		points.push_back(intervals[i].first);
//		points.push_back(intervals[i].second);
//	}
//
//	std::sort(intervals, intervals + n);
//	std::sort(points.begin(), points.end());
//	points.erase(std::unique(points.begin(), points.end()), points.end());
//
//	for (int i = 0; i < n; i++) {	//좌표 압축
//		intervals[i].first = std::lower_bound(points.begin(), points.end(), intervals[i].first) - points.begin();
//		intervals[i].second = std::lower_bound(points.begin(), points.end(), intervals[i].second) - points.begin();
//	}
//
//	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
//	int usedCnt = 0;
//	LL ans = 0;
//
//	for (int i = 0; i < points.size()-1; i++) {
//		while (usedCnt < n && intervals[usedCnt].first <= i) pq.push(intervals[usedCnt++].second);
//
//		ans = (ans + comb(pq.size(), m)) % PRIME;	// 한 점 구간 계산
//
//		while (!pq.empty() && pq.top() <= i) pq.pop();
//
//		ans = (ans + comb(pq.size(), m) * (points[i+1] - points[i]-1)) % PRIME; // 점과 점사이 구간 계산
//		std::cout << ans << '\n';
//		
//	}
//
//	while (usedCnt < n && intervals[usedCnt].first <= points.size()-1) pq.push(intervals[usedCnt++].second);
//	while (!pq.empty() && pq.top() < points.size()-1) pq.pop();
//	ans = (ans + comb(pq.size(), m)) % PRIME; // 마지막 점 계산
//
//	std::cout << ans;
//	return 0;
//}