// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// dp (ddr 문제 처럼) (x, 메모리 부족) 
// ddr처럼 풀되 메모리 아낄 방법?
// int dp[1000000][1000000]로 필요 (dp[i][k] = 경찰차1이 i 경찰차2가 k에 있을 때 비용의 최소 값)
// vector<{intpair, intpair, n}> dp;	// 중복을 줄일 방법이..
//
// 
// (a,b), (c,d) 와 (c, d), (a, b) 는 같음 -> 이거로 배열 크기 줄일 수 있을 듯
// 
// {int ,int} dpX[1000][1000], dpY[1000][1000];
//	x,y 따로 나눠서 계산하기.(아닌거 가타)
// 
// (1,1), (n,n) -> (a,b)
// 
// (a,b), (n,n) / (1,1) (a,b) -> (c,d)
// 
// (c,d), (n,n) / (a,b) (c,d) / (c,d), (n,n) / (1,1) (c,d)
// = (a,b) (c,d) / (c,d), (n,n) / (1,1) (c,d) -> (e, f)
//
// (e,f) (c,d) / (e,f), (n,n) / (e,f) (c,d) / (a,b) (e,f) / (c,d), (e,f) / (1,1) (e,f)
// = (e,f) (c,d) / (e,f), (n,n) / (a,b) (e,f) / (1,1) (e,f)
//
// 겹치는 거 빼면 새로운 경우가 1개씩 늘어나니깐 2^n개 만들어 지지 않고 1000개정도인가?
// 중복되는 거 확인하는 방법, map써서 dp하는 거 ㄱㅊ?
//
//

//#include <iostream>
//#include <map>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using intpair = std::pair<int, int>;
//
//struct DP_TYPE{		//exert(pos1 < pos2)
//	intpair pos1;
//	intpair pos2;
//
//	DP_TYPE(intpair one, intpair two) : pos1(one), pos2(two) {}
//	bool operator< (const DP_TYPE& a) const {
//		return (pos1 == a.pos1 ? pos2 < a.pos2 : pos1 < a.pos1);
//	}
//	bool operator== (const DP_TYPE& a) {
//		return pos1 == a.pos1 && pos2 == a.pos2;
//	}
//	bool operator!= (const DP_TYPE& a) {
//		return !(*this == a);
//	}
//};
//
//
//intpair eventPos[1001];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//
//	std::vector<DP_TYPE> dp[2];
//	std::vector<int> cost[2];
//	std::vector<std::string> his[2];
//
//	dp[0].push_back({ {1, 1} , {n, n} });
//	cost[0].push_back(0);
//	his[0].push_back("\n");
//
//	for (int i = 1, x, y; i <= m; i++) {
//		dp[i % 2].clear();
//		cost[i % 2].clear();
//		his[i % 2].clear();
//
//		std::cin >> x >> y;
//
//		for (std::vector<DP_TYPE>::iterator prePos = dp[(i + 1) % 2].begin(); prePos != dp[(i + 1) % 2].end(); prePos++) {
//			// car1 move
//			DP_TYPE newPos({ x, y }, prePos->pos2);
//			int newCost = cost[(i + 1) % 2][prePos - dp[(i + 1) % 2].begin()] + std::abs(newPos.pos1.first - prePos->pos1.first) + std::abs(newPos.pos1.second - prePos->pos1.second);
//
//			bool flag = false;
//			if (newPos.pos1 > newPos.pos2) {
//				std::swap(newPos.pos1, newPos.pos2);
//				flag = true;
//			}
//
//			std::vector<DP_TYPE>::iterator existPos = dp[i % 2].end();
//			for (std::vector<DP_TYPE>::iterator k = dp[i % 2].begin(); k != dp[i % 2].end(); k++) {
//				bool flag2 = false;
//				
//				if (k->pos1 > k->pos2) {
//					std::swap(k->pos1, k->pos2);
//					flag2 = true;
//				}
//				
//				if (*k == newPos) existPos = k;
//
//				if (flag2) {
//					std::swap(k->pos1, k->pos2);
//				}
//			}
//
//			if (flag) {
//				std::swap(newPos.pos1, newPos.pos2);
//			}
//
//			if (existPos == dp[i % 2].end()) {
//				dp[i % 2].push_back(newPos);
//				cost[i % 2].push_back(newCost);
//				his[i % 2].push_back(his[(i + 1) % 2][prePos - dp[(i + 1) % 2].begin()] + "1\n");
//			}
//			else {
//				if (cost[i % 2][existPos - dp[i % 2].begin()] > newCost) {
//					dp[i % 2][existPos - dp[i % 2].begin()] = newPos;
//					cost[i % 2][existPos - dp[i % 2].begin()] = newCost;
//					his[i % 2][existPos - dp[i % 2].begin()] = (his[(i + 1) % 2][prePos - dp[(i + 1) % 2].begin()] + "1\n");
//				}
//			}
//
//
//			// car2 move
//
//			newPos = { prePos->pos1, { x, y } };
//			newCost = cost[(i + 1) % 2][prePos - dp[(i + 1) % 2].begin()] + std::abs(newPos.pos2.first - prePos->pos2.first) + std::abs(newPos.pos2.second - prePos->pos2.second);
//
//			flag = false;
//
//			if (newPos.pos1 > newPos.pos2) {
//				std::swap(newPos.pos1, newPos.pos2);
//				flag = true;
//			}
//
//			existPos = dp[i % 2].end();
//			for (std::vector<DP_TYPE>::iterator k = dp[i % 2].begin(); k != dp[i % 2].end(); k++) {
//				bool flag2 = false;
//
//				if (k->pos1 > k->pos2) {
//					std::swap(k->pos1, k->pos2);
//					flag2 = true;
//				}
//
//				if (*k == newPos) existPos = k;
//
//				if (flag2) {
//					std::swap(k->pos1, k->pos2);
//				}
//			}
//
//
//			if (flag) {
//				std::swap(newPos.pos1, newPos.pos2);
//			}
//
//			if (existPos == dp[i % 2].end()) {
//				dp[i % 2].push_back(newPos);
//				cost[i % 2].push_back(newCost);
//				his[i % 2].push_back(his[(i + 1) % 2][prePos - dp[(i + 1) % 2].begin()] + "2\n");
//			}
//			else {
//				if (cost[i % 2][existPos - dp[i % 2].begin()] > newCost) {
//					dp[i % 2][existPos - dp[i % 2].begin()] = newPos;
//					cost[i % 2][existPos - dp[i % 2].begin()] = newCost;
//					his[i % 2][existPos - dp[i % 2].begin()] = (his[(i + 1) % 2][prePos - dp[(i + 1) % 2].begin()] + "2\n");
//				}
//			}
//		}
//
//		//for (DP_TYPE d : dp[i % 2]) {
//		//	printf("( %d, %d ) , ( %d, %d ) / ", d.pos1.first, d.pos1.second, d.pos2.first, d.pos2.second);
//		//}std::cout << '\n';
//		//for (int c : cost[i % 2]) {
//		//	printf("%d / ", c);
//		//}std::cout << '\n';
//		//for (auto& h : his[i % 2]) {
//		//	std::cout << h << " / ";
//		//}std::cout << '\n';
//
//	}
//
//	int ans = 1e9, ansPos;
//	for (std::vector<int>::iterator i = cost[m % 2].begin(); i != cost[m % 2].end(); i++) {
//
//		if (ans > *i) {
//			ans = *i;
//			ansPos = i - cost[m % 2].begin();
//		}
//	}
//
//	std::cout << ans;
//	std::cout << his[m % 2][ansPos];
//
//	return 0;
//}
	//std::map<DP_TYPE, int> dp[1001];
	//
	//dp[0].insert({ {{1,1}, {n,n}}, 0 });
	//for (int i = 1; i <= m; i++) {
	//	std::cin >> eventPos[i].first >> eventPos[i].second;

	//	for (const std::pair<DP_TYPE, int>& k : dp[i-1]) {
	//		//car 1
	//		DP_TYPE newPos = { {eventPos[i].first, eventPos[i].second}, k.first.pos2 };
	//		int newCost = k.second + std::abs(newPos.pos1.first - k.first.pos1.first) + std::abs(newPos.pos1.second - k.first.pos1.second);

	//	//	printf("(%d, %d), (%d, %d) / ", newPos.pos1.first, newPos.pos1.second, newPos.pos2.first, newPos.pos2.second);

	//		if (newPos.pos1 > newPos.pos2) {
	//			std::swap(newPos.pos1, newPos.pos2);
	//		}


	//		if (dp[i].find(newPos) == dp[i].end()) {
	//			dp[i].insert({ newPos,  newCost });
	//		}
	//		else {
	//			if (dp[i][newPos] > newCost) {

	//				dp[i][newPos] = newCost;
	//			}
	//		}

	//		//car 2

	//		newPos = { k.first.pos1, {eventPos[i].first, eventPos[i].second} };
	//		newCost = k.second + std::abs(newPos.pos2.first - k.first.pos2.first) + std::abs(newPos.pos2.second - k.first.pos2.second);

	//		//printf("(%d, %d), (%d, %d) / ", newPos.pos1.first, newPos.pos1.second, newPos.pos2.first, newPos.pos2.second);

	//		if (newPos.pos1 > newPos.pos2) {
	//			std::swap(newPos.pos1, newPos.pos2);
	//		}


	//		if (dp[i].find(newPos) == dp[i].end()) {
	//			dp[i].insert({ newPos,  newCost });
	//		}
	//		else {
	//			if (dp[i][newPos] > newCost) {
	//				dp[i][newPos] = newCost;
	//			}
	//		}
	//	}

	//	//std::cout <<'\n' <<dp[i].size() << '\n';
	//}


	//int ans = 1e9; DP_TYPE ansEn({ {0, 0} ,{0, 0} });
	//for (const std::pair<DP_TYPE, int>& i : dp[m]) {
	//	if (ans <= i.second) {
	//		continue;
	//	}

	//	ans = i.second;
	//	ansEn = i.first;
	//}

	//std::cout << ans << '\n';

	//std::vector<int> sequence;

	//for (int i = m; i > 0; i--) {
	//	if (ansEn.pos1 == eventPos[i]) {
	//		bool flag = false;


	//		for (const std::pair<DP_TYPE, int>& k : dp[i-1]) {
	//			if (k.second + std::abs(k.first.pos1.first - eventPos[i].first) + std::abs(k.first.pos1.second - eventPos[i].second) == ans) {
	//				ansEn = k.first;
	//				ans = k.second;
	//				flag = true;
	//			}
	//		}

	//		if (flag) {
	//			sequence.push_back(1);
	//		}
	//	}

	//	if (ansEn.pos2 == eventPos[i]) {
	//		bool flag = false;


	//		for (const std::pair<DP_TYPE, int>& k : dp[i - 1]) {
	//			if (k.second + std::abs(k.first.pos2.first - eventPos[i].first) + std::abs(k.first.pos2.second - eventPos[i].second) == ans) {
	//				ansEn = k.first;
	//				ans = k.second;
	//				flag = true;
	//			}
	//		}

	//		if (flag) {
	//			sequence.push_back(2);
	//		}
	//	}
	//}

	//for (std::vector<int>::reverse_iterator i = sequence.rbegin(); i != sequence.rend(); i++) {
	//	std::cout << *i << '\n';
	//}


/*
1,1 / 1000, 1000 -> 309
2

1, 1 / 936, 755
1
1
2
1
2
2
2
2
1
2
2
2
2
1
2
1
1
1
1
1
2
2
1
1
1
2
1
1
1
*/