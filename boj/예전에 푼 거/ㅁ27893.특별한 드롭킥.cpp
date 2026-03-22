// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

/*
 57 4
 .X.X.X.X.X.XXXXXXXXXXXXXXXXXXXXXXXXX....XXXXXXXXXXXXXXXXX
 == .x.x.x.x.x.x....x
*/
// 1+2+1+2+1+2+1+2+1+2+1+2 = 12+6 = 18
// 1+2+1+2+4+2 = 12
// 2+1+2+1+2+4+2 = 
// 작은 덩어리들을 큰 덩어리로 합치는 게 중요
//
// X.X... / XX..X.
// -> 5 / 6
// 
// 떨어진 거리가 작은 것 부터 채워주면 최소 시간 가능?
// 
// .XXXXX.X.X.X.
// // 1+2+1+2+1+2+1+2+1 
// .XXX.X.X.XXX.
// // 5 + 8
//
//
// 벽끼리 떨어진 거리가 작은 것 부터 채워주면 최소 시간 가능
// .개수 x덩어리 개수 세기
// {떨어진 거리, 끝난 위치} arr[] 오름차순 정렬
// 처음부터 벽 다 떨어질 때까지 채움
// 채울때마다 x덩이러 개수--, 거리만큼 .개수 빼기
// 
// 더이상 못 채운다.
// 남은 벽개수 .개수에 빼기
// 
// .개수 + x덩어리 개수*2
// 

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using intpair = std::pair<int, int>;
//char passage[200200];
//
//int main() {
//	int n, m;
//	std::cin >> n >> m;
//	std::cin >> passage;
//
//	int i = 0;
//	while (i < n && passage[i++] == '.');
//
//	std::vector<intpair> vec;
//	vec.reserve(100100);
//
//	while (i < n) {
//		while (i < n && passage[i] == 'X') i++;
//		int cnt = 0;
//
//		while (i < n && passage[i] == '.') cnt++, i++;
//		
//
//		vec.push_back({ cnt, i - 1 });
//	}
//
//	if (!vec.empty() && vec.back().second == n - 1) vec.pop_back();
//
//	std::sort(vec.begin(), vec.end());
//
//	/*for (auto i : vec) {
//		std::cout << (i.first) << ' ' <<( i.second) << '\n';
//	}*/
//
//	for (std::vector<intpair>::iterator i = vec.begin(); i != vec.end() && m - i->first >= 0; i++) {
//		for (int k = i->second - i->first + 1; k <= i->second; k++) {
//			passage[k] = 'X';
//		}
//		m -= i->first;
//	}
//	//
//	//for (int i = 0; i < n; i++) {
//	//	std::cout << passage[i];
//	//}std::cout << '\n';
//
//	int wallChunk = 0, space = 0;
//
//	for (int i = 1, cnt = 1; i <= n; i++, cnt++) {
//		if (passage[i] != passage[i - 1]) {
//			if (passage[i - 1] == '.') {
//				space += cnt;
//			}
//			else {
//				wallChunk++;
//			}
//
//			cnt = 0;
//		}
//	}
//
//	if (!wallChunk) {
//		std::cout << std::min(space - m + 2, space);
//	}
//	else {
//		std::cout << space - m + wallChunk * 2;
//	}
//
//	return 0;
//}
// 
// 이거 왜 안된거야 ㅅㅂ?
//std::vector<int> arr;
//
//int main() {
//	int n, m;
//	std::cin >> n >> m;
//
//	int wallCnt = 0, spaceCnt = 0;
//	char cur, pre = 0, cnt = 1;
//
//	for (std::cin >> pre; pre == '.'; std::cin >> pre) {
//		spaceCnt++;
//		if (spaceCnt == n) break;
//	}
//	if (spaceCnt != n) {
//		for (int i = spaceCnt + 1; i < n; i++, cnt++) {
//			std::cin >> cur;
//
//			if (pre != cur) {
//				if (pre == 'X') {
//					wallCnt++;
//				}
//				else {
//					arr.push_back(cnt);
//					spaceCnt += cnt;
//				}
//
//				cnt = 0;
//			}
//
//			pre = cur;
//		}
//
//		if (pre == 'X') {
//			wallCnt++;
//		}
//		else if (pre == '.') {
//			spaceCnt += cnt;
//		}
//	}
//
//	std::sort(arr.begin(), arr.end());
//
//	if (arr.size() != 0) {
//		for (std::vector<int>::iterator i = arr.begin(); i != arr.end() && m - *i >= 0; i++) {
//			wallCnt--;
//			spaceCnt -= *i;
//			m -= *i;
//		}
//	}
//
//	if (m > 0 && wallCnt == 0) {
//		std::cout << std::min(spaceCnt - m + 2, spaceCnt);
//	}
//	else {
//		std::cout << spaceCnt - m + wallCnt * 2;
//	}
//
//	return 0;
//}