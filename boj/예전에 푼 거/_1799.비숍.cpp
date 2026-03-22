// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 부르트포스, 구현
// map은 1차원으로
// 대각선은 1차원 배열로 표현
// 오른쪽 아래로 가는 대각선 arr[n*2-1] 
// // (a, b)의 대각선 확인 = arr[a + n - b - 1]  확인
//
// 왼쪽 아래로 가는 대각선 arr[n*2-1]
// // (a, b)의 대각선 확인 = arr[a+b] 확인

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//int n;
//bool map[100];
//bool rd[19], ld[19]; // 오른쪽 아래, 왼쪽 아래
//
//int dfs_odd(int cur) {
//	if (cur >= n*n) {
//		return 0;
//	}
//
//	int x = cur % n, y = cur / n;
//	int max = dfs_odd(cur+2);
//
//	if (map[cur] && !rd[x + n - y - 1] && !ld[x + y]) { 
//		ld[x + y] = rd[x + n - y - 1] = true;
//
//		max = std::max(max, dfs_odd(cur + 2) + 1);
//
//		ld[x + y] = rd[x + n - y - 1] = false;
//	}
//	
//
//	return max;
//}
//
//int dfs_even(int cur) {
//	if (cur >= n * n) {
//		return 0;
//	}
//
//	int x = cur % n, y = cur / n;
//	int next = (x == n - 2 ? cur + 3 : (x == n - 1 ? cur + 1 : cur + 2));
//
//	int max = dfs_even(next);
//
//	if (map[cur] && !rd[x + n - y - 1] && !ld[x + y]) {
//		ld[x + y] = rd[x + n - y - 1] = true;
//
//		max = std::max(max, dfs_even(next) + 1);
//
//		ld[x + y] = rd[x + n - y - 1] = false;
//	}
//
//
//	return max;
//}
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	std::cin >> n;
//
//	for (int i = 0; i < n*n; i++) {
//		std::cin >> map[i];
//	}
//
//	if (n % 2) {
//		std::cout << dfs_odd(0) + dfs_odd(1);
//	}
//	else {
//		std::cout << dfs_even(0) + dfs_even(1);
//	}
//
//	return 0;
//}