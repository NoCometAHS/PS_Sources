// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 링크드 리스트, 이진 탐색, 수학
//  
// 상어 없애려면 무게를 기준으로 이진 탐색
// 
// 상어의 이동은
// 일단 끝까지 이동시겨둠 
// (남은거리)%(길이-1)을 d라고 했을 떼
// (남은거리-1)/(길이-1)이 홀수면 방향 그대로
//							짝수면 방향 바꾸기
// (남은거리-1)/(길이-1)이 홀수면 바라보는 반대 방향 끝에서 d만큼 이동
//						짝수면 바라보는 방향 끝에서 d만큼 이동 
// 규칙 틀렸나봄
//
//#include <iostream>
//#include <algorithm>
//#include <list>
//#include <vector>
//
//struct SHARK {
//	int x;
//	int y;
//	int vel;
//	int dir;
//	int size;
//
//	SHARK(int x, int y, int vel, int dir, int size) : x(x), y(y), vel(vel), dir(dir), size(size){}
//};
//
//int dx[4] = { 0, 0, 1, -1 }, dy[4] = { -1, 1, 0 , 0 };
//int water[2][101][101]; int r, c;
//std::vector<SHARK> sharks;
//bool chk[10001];
//
//SHARK move_shark(SHARK sh) {
//	for (int i = sh.vel; i > 0; ) {
//		switch (sh.dir)
//		{
//		case 0:
//			if (i> sh.y - 1) {
//				i -= sh.y-1;
//				sh.y = 1;
//				sh.dir = 1;
//			}
//			else {
//				sh.y = sh.y - i;
//				i = 0;
//			}
//			break;
//
//		case 1:
//			if (i > r - sh.y) {
//				i -= r - sh.y;
//				sh.y = r;
//				sh.dir = 0;
//			}
//			else {
//				sh.y = sh.y + i;
//				i = 0;
//			}
//			break;
//
//		case 2:
//			if (i > c - sh.x) {
//				i -= c - sh.x;
//				sh.x = c;
//				sh.dir = 3;
//			}
//			else {
//				sh.x = sh.x + i;
//				i = 0;
//			}
//			break;
//		case 3:
//			if (i > sh.x - 1) {
//				i -= sh.x - 1;
//				sh.x = 1;
//				sh.dir = 2;
//			}
//			else {
//				sh.x = sh.x - i;
//				i = 0;
//			}
//			break;
//		}
//	}
//
//
//	return sh;
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int m;
//	std::cin >> r >> c >> m;
//
//	
//	for (int i = 0, x, y, v, d, s; i < m; i++) {
//		std::cin >> y >> x >> v >> d >> s;
//		
//		d--;
//
//		sharks.push_back({ x,y,v,d,s });
//		water[1][y][x] = s;
//		chk[s] = true;
//	}
//
//	int ans = 0;
//	
//	for (int i = 1; i <= c; i++) {
//		int capturedSize=0;
//
//		for (int k = 0; k <= r; k++) {
//			if (!water[i%2][k][i]) continue;
//			capturedSize = water[i%2][k][i];
//			water[i%2][k][i] = 0;
//			chk[capturedSize] = false;
//			break;
//		}
//
//		ans += capturedSize;
//		
//		for (SHARK& cur : sharks) {
//			if (!chk[cur.size]) continue;
//
//			water[i % 2][cur.y][cur.x] = 0;
//
//			cur = move_shark(cur);
//
//			if (water[(i + 1) % 2][cur.y][cur.x]) {
//				if (water[(i + 1) % 2][cur.y][cur.x] < cur.size) {
//					chk[water[(i + 1) % 2][cur.y][cur.x]] = false;
//					water[(i + 1) % 2][cur.y][cur.x] = cur.size;
//				}
//				else {
//					chk[cur.size] = false;
//				}
//				
//			}
//			else {
//				water[(i + 1) % 2][cur.y][cur.x] = cur.size;
//			}
//		}
//
//	}
//
//	std::cout << ans;
//	return 0;
//}