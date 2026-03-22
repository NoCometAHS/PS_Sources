// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 쉽게 -> 명료히
// 먼저 생각하기

// 
// 구현

#include <iostream>

//#include <iostream>
//
//char str[51];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	std::cin >> str;
//
//	int con = 0, i;
//	bool ans = true;
//	for (i = 0; str[i]; i++) {
//		if (str[i] == 'X') {
//			str[i] = 'A';
//			con++;
//		}
//		else {
//			int left = con % 4;
//			if (left == 2) {
//				str[i - 1] = 'B';
//				str[i - 2] = 'B';
//			}
//			else if (left % 2) {
//				ans = false;
//				break;
//			}
//
//			con = 0;
//		}
//	}
//
//	int left = con % 4;
//	if (left == 2) {
//		str[i - 1] = 'B';
//		str[i - 2] = 'B';
//	}
//	else if (left % 2) {
//		ans = false;
//	}
//
//	std::cout << (ans ? str : "-1");
//
//	return 0;
//}