////
//// 구현
//// 1111 1111 1111 1111 1111
//// 에서 0, 1, 3, 5개 비트가 빠졌을 때 경우로 숫자 채우기
//// (x, 52점)
//// 
//// 구현
//// 비트 절반으로 나누고
//// 1000개는 왼쪽 10개 조합으로
//// 나머지는 오른쪽 10개 조합으로
////
//
//#include <iostream>
//#include <fstream>
//#include <vector>
//
//#pragma warning (disable : 4996)
//std::vector<int> ans;
//
//void dfs_left(int cur, int num, int lv, int left = 10) {
//	if (lv == 10) {
//		return;
//	}
//
//	for (int i = cur; i < 10; i++) {
//		ans.push_back(num & ~(1 << (i + left)));
//		
//		dfs_left(i + 1, num & ~(1 << (i + left)), lv + 1, left);
//	}
//
//	return;
//}
//
//
//int main() {
//	std::ofstream wf;
//	wf.open("C:/Users/user/Desktop/ans.txt");
//	
//
//	dfs_left(0, (1 << 20) - 1, 0);
//	dfs_left(0, (1 << 20) - 1, 0, 0);
//
//	for (int i = 0; i < 2000; i++) {
//		wf << ans[i] << '\n';
//	}
//
//	return 0;
//}