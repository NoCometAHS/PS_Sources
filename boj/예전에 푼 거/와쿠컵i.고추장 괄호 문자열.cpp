//
// 부르트 포스
//

//#include <iostream>
//#include <vector>
//
//std::vector<int> pos;
//char str[21];
//
//bool is_correct() {
//	int open = 0;
//	for (int i = 0; str[i]; i++) {
//		if (str[i] == '(') {
//			
//			open++;
//		}
//		else {
//			if (open == 0) {
//				return false;
//			}
//			open--;
//		}
//	}
//	return open == 0;
//}
//
//bool dfs(int lv) {
//	if (lv == pos.size()) {
//
//		return is_correct();
//	}
//
//	str[pos[lv]] = '(';
//	if (dfs(lv + 1)) return true;
//
//	str[pos[lv]] = ')';
//	if (dfs(lv + 1)) return true;
//
//	return false;
//}
//
//int main() {
//	int n;
//	std::cin >> n;
//
//	for (int i = 0;  std::cin >> str[i]; i++) {
//		if (str[i] == 'G') pos.push_back(i);
//	}
//
//	dfs(0);
//
//	std::cout << str;
//}