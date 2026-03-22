//
// ±¸Çö
//

//#include <iostream>
//#include <set>
//#include <string>
//
//bool is_cheese(const std::string& a) {
//	int st = a.size() - 6;
//
//	if (st < 0) return false;
//
//	for (int i = 0; i < 6; i++) {
//		if ("Cheese"[i] != a[st + i]) return false;
//	}
//
//	return true;
//}
//
//int main() {
//	int n;
//	std::cin >> n;
//
//	std::set<std::string> toppings;
//	std::string temp;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> temp;
//		
//		if (!is_cheese(temp)) continue;
//
//		toppings.insert(temp);
//	}
//
//	std::cout << (toppings.size() > 3 ? "yummy" : "sad");
//
//	return 0;
//}