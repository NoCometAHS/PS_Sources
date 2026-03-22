////
//// 구현
//// 
//// 어디까지 비가 내리던 1층은 무조건 비를 맞게 된다.
//// 따라서 1층 위의 어디가 무너진다면 그 밑의 층은 무조건 무너진다.
//// 즉 1층만 비 어느정도 맞았는 지 보면 됨
////
//
//#include <iostream>
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m, dura;
//	std::cin >> n >> m >> dura;
//
//	int i, ti, ri;
//	for (i = 0; i < m; i++) {
//		std::cin >> ti >> ri;
//
//		dura -= ri;
//		if (dura < 0) break;
//	}
//
//	if (i == m) {
//		std::cout << -1;
//	}
//	else {
//		std::cout << i + 1 << " " <<  1;
//	}
//
//	return 0;
//}