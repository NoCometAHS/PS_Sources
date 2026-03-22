// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저생각하기

//
// map, 분리 집합
// 
// 순열 사이클 분할 감잡으려고 푼 문제 인데 이게 머누;
// 
////
//
//#include <iostream>
//#include <map>
//#include <string>
//
//int setTree[20];
//int setCnt;
//
//int find_par(int cur) {
//	if (cur == setTree[cur]) return cur;
//	else return setTree[cur] = find_par(setTree[cur]);
//}
//
//void union_set(int a, int b) {
//	a = find_par(a), b = find_par(b);
//
//	if (a == b)
//		return;
//
//	setTree[b] = a;
//	setCnt--;
//
//	return;
//}
//
//
//int main() {
//	int n;
//	std::map<std::string, int> toNum;
//
//	std::cin >> n;
//	int tc = 1;
//	while (n) {
//		setCnt = n;
//		for (int i = 0; i < n; i++) setTree[i] = i;
//
//		toNum.clear();
//
//		int nameCnt = 0;
//		std::string name1, name2;
//		for (int i = 0; i < n; i++) {
//			std::cin >> name1 >> name2;
//			if (toNum.find(name1) == toNum.end()) {
//				toNum[name1] = nameCnt++;
//			}
//			if (toNum.find(name2) == toNum.end()) {
//				toNum[name2] = nameCnt++;
//			}
//
//			union_set(toNum[name1], toNum[name2]);
//		}
//
//		std::cout << tc++ << " " << setCnt << '\n';
//		std::cin >> n;
//	}
//
//	return 0;
//}