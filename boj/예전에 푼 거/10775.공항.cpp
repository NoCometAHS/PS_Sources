// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 비행기가 온 순서 고려할 필요 없음 무조건 Gi가 큰거 먼저 박아두면 최대로 도킹 가능 (x, 문제 잘못 읽었다, 도킹 실패시 모든 이후의 도킹 불가능해서 순서가 중요)
//
// 항상 자신의 최대 도킹지점에 도킹하는게 좋음
//
// 그리디
//
// dp[i] : i가 나왔을 때 최소 i부터 i - dp[i] + 1 정도 까지는 이미 차 있음 
// // 0이면 차있지 않음
// 
// 0, 1,1,2,0
// 
// 와우 이거 분리 집합으로 더 편하게 된다. 미쳤넹
//#include <iostream>
//
//int arrived[100001];
//
//int main() {
//	int n, m;
//
//	std::cin >> n >> m;
//
//	int cnt = 0;
//	for (int i = 0, airplane; i < m; i++) {
//		std::cin >> airplane;
//
//		while (airplane > 0 && arrived[airplane]) {
//			int temp = airplane - arrived[airplane];
//			
//			arrived[airplane] += arrived[temp];
//
//			airplane -= arrived[airplane];
//		}
//
//		arrived[airplane]++;
//
//		if (airplane <= 0) break;
//
//		cnt++;
//	}
//
//	std::cout << cnt;
//
//	return 0;
//}