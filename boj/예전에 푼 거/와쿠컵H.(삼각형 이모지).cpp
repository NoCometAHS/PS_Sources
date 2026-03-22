////
//// 부모 정점에 다 연결해 버리면 그만임
//// 수학, 그리디, 구성적
////
//
//#include <iostream>
//
//int main() {
//	long long n;
//	std::cin >> n;
//
//	n--;
//	
//	std::cout << n * (n - 1) + n << '\n';
//	
//	for (int i = 2; i <= n+1; i++) {
//		std::cout << 1 << ' ' << i << '\n';
//	}
//
//	return 0;
//}