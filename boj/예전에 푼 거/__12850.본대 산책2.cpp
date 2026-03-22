// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 밸만 포드 비슷한 느낌으로
// 행렬 제곱 ㅇㅇ
//
//  *** 그래프 행렬과 시작점을 1로 표시한 1*n 행렬을 곱하면 어디에 몇번 갈 수 있는지 알 수 있음 또한
//      그래프 행렬의 n제곱은 어디에 n번 움직여서 몇번 갈 수 있는 지 알 수 있음
// 

/*
지도 (from / to)

0 1 1 0 0 0 0 0
1 0 1 1 0 0 0 0
1 1 0 1 1 0 0 0
0 1 1 0 1 1 0 0
0 0 1 1 0 1 1 0
0 0 0 1 1 0 0 1
0 0 0 0 1 0 0 1
0 0 0 0 0 1 1 0

X

1
0
0
0
0
0
0
0

=

*/

//#include <iostream>
//
//#define BigNum 1000000007
//
//using LL = unsigned long long;
//
//struct matrix9_9 {
//	LL arr[9][9];
//
//	matrix9_9() {
//		for (int i = 0; i < 9; i++) {
//			for (int k = 0; k < 9; k++) {
//				arr[i][k] = 0;
//			}
//		}
//	}
//
//	matrix9_9 operator*(const matrix9_9& a) const {
//		matrix9_9 ret;
//
//		for (int i = 0; i < 9; i++) {
//			for (int k = 0; k < 9; k++) {
//				for (int p = 0; p < 9; p++) {
//					ret.arr[i][k] += (arr[i][p] * a.arr[p][k]) % BigNum;
//					ret.arr[i][k] %= BigNum;
//				}
//			}
//		}
//
//		return ret;
//	}
//};
//
//matrix9_9 myPow(const matrix9_9& b, int cnt) {
//	if (cnt == 1) {
//		return b;
//	}
//
//	matrix9_9 temp = myPow(b, cnt / 2);
//
//	if (cnt % 2) {
//		return b * temp * temp;
//	}
//	else {
//		return temp * temp;
//	}
//}
//
//
//bool graph[9][9] = {
//	{ 0, 1, 1, 0, 0, 0, 0, 0 },
//	{ 1, 0, 1, 1, 0, 0, 0, 0 },
//	{ 1, 1, 0, 1, 1, 0, 0, 0 },
//	{ 0, 1, 1, 0, 1, 1, 0, 0 },
//	{ 0, 0, 1, 1, 0 ,1 ,1, 0 },
//	{ 0, 0, 0, 1, 1, 0, 0, 1 },
//	{ 0, 0, 0, 0, 1, 0, 0, 1 },
//	{ 0, 0, 0, 0 ,0, 1, 1, 0 }
//};
//
//int main() {
//	int n;
//
//	std::cin >> n;
//	
//	matrix9_9 g;
//	for (int i = 0; i < 9; i++) {
//		for (int k = 0; k < 9; k++) {
//			g.arr[i][k] = graph[i][k];
//		}
//	}
//
//	std::cout << myPow(g, n).arr[0][0];
//
//	return 0;
//}