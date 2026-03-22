// 
// 브루트 포스
//
//
//#include <iostream>
//
//char str[2200];
//
//bool is_vitamin(int Aen, int Bst) {
//	bool flag = false;
//
//	for (int i = 0; i <= Aen; i++) {
//		if (str[i] != str[Bst + i]) {
//			if (flag) return false;
//
//			flag = true;
//		}
//	}
//
//	return flag;
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n >> str;
//
//	bool ans = false;
//
//	for (int i = 0; i < n - 1 && !ans; i++) {
//		ans = is_vitamin(i, n - i - 1);
//	}
//
//	std::cout << (ans ? "YES" : "NO");
//
//	return 0;
//}