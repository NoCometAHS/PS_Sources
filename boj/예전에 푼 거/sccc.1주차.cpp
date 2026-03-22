// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기
// 동전 1
//#include <iostream>
//#include <set>
//
//int dp[10001];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//
//	std::set<int> coins;
//	for (int i = 0, t; i < n; i++) {
//		std::cin >> t;
//		coins.insert(t);
//	}
//
//	for (int i = 1; i <= m; i++) {
//		dp[i] = 1e9;
//		for (const int& coin : coins) {
//			if (i - coin < 0 || dp[i - coin] == 1e9) continue;
//
//			dp[i] = std::min(dp[i], dp[i - coin] + 1);
//		}
//	}
//
//	std::cout << (dp[m] == 1e9 ? -1 : dp[m]);
//	return 0;
//}

// 평범한 배낭

//#include <iostream>
//
//int dp[100001];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//
//	for (int i = 0, w, v; i < n; i++) {
//		std::cin >> w >> v;
//
//		for (int k = m; k >= w; k--) {
//			dp[k] = std::max(dp[k], dp[k - w] + v);
//		}
//	}
//
//	std::cout << dp[m];
//	return 0;
//}

// 앱

//#include <iostream>
//
//int dp[10001];
//int mem[100], c[100];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> mem[i];
//	}
//	for (int i = 0; i < n; i++) {
//		std::cin >> c[i];
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int k = 10000; k >= c[i]; k--) {
//			dp[k] = std::max(dp[k], dp[k - c[i]] + mem[i]);
//		}
//	}
//
//	int ans = 0;
//	while (dp[ans++] < m);
//
//	std::cout << ans-1;
//	return 0;
//}

// __평범한 배낭 2

//
// dp 요소들은 항상 정렬상태
// 일단 전부다 찾는 방식 해봐야지
// 개수를 늘리는게 다음으로 진행하는 것보다 낫다면 늘리기 (x 적은게 필요 할 수 있음)
// 무게를 하나씩 추가하는 dp로?
// 아이템은 최대로 무개만큼의 개수만 가져가기 가능 
// 굳굳 역발상


//#include <iostream>
//
//int dp[10001][101];		//dp[i][j] : 무게가 i이하고 최대 가치일때 쓴 j번째 아이템 개수
//int maxVal[10001];
//int items[100][3];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//	
//	for (int i = 0; i < n; i++) {
//		std::cin >> items[i][0] >> items[i][1] >> items[i][2];
//	}
//
//	for (int weight = 1; weight <= m; weight++) {
//		int selected = -1;
//		for (int item = 0; item < n; item++) {
//			if (weight < items[item][0] || dp[weight - items[item][0]][item] + 1 > items[item][2]) continue;
//
//			if (maxVal[weight] < maxVal[weight - items[item][0]] + items[item][1]) {
//				maxVal[weight] = maxVal[weight - items[item][0]] + items[item][1];
//				selected = item;
//			}
//		}
//
//		if (selected != -1) {
//			for (int k = 0; k < 100; k++) {
//				dp[weight][k] = dp[weight - items[selected][0]][k];
//			}
//			dp[weight][selected]++;
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i <= m; i++) ans = std::max(ans, maxVal[i]);
//	std::cout << ans;
//	return 0;
//}

// lcs 2
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int dp[1000];
//std::vector<char> child[1000];
//char str[2][1001];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	std::cin >> str[0] >> str[1];
//	
//	int ans = 0, ansPos;
//
//	for (int i = 0; str[0][i]; i++) {
//		int max = 0,  maxIdx = -1;
//
//		for (int k = 0; str[1][k]; k++) {
//			int temp = dp[k];
//
//			if (str[0][i] == str[1][k]) {
//				if (dp[k] < max + 1) {
//					dp[k] = max + 1;
//
//					if (maxIdx != -1) {
//						child[k].clear();
//						child[k] = child[maxIdx];
//						child[k].push_back(str[1][maxIdx]);
//					}
//				}
//				
//				if (ans < dp[k]) {
//					ans = dp[k];
//					ansPos = k;
//				}
//			}
//
//			if (max < temp) {
//				max = temp;
//				maxIdx = k;
//			}
//
//		}
//	}
//	std::cout << ans << '\n';
//
//	if (ans) {
//		for (const char& i : child[ansPos]) {
//			std::cout << i;
//		}
//
//		std::cout << str[1][ansPos];
//	}
//	return 0;
//}


// 가장 긴 증가하는 수열 2

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//std::vector<int> dp;
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	dp.push_back(0);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 0, num; i < n; i++) {
//		std::cin >> num;
//
//		std::vector<int>::iterator pos = std::lower_bound(dp.begin(), dp.end(), num);
//
//		if (pos == dp.end()) {
//			dp.push_back(num);
//		}
//		else {
//			*pos = num;
//		}
//	}
//
//	std::cout << dp.size() - 1;
//
//	return 0;
//}


// 보석 도둑
// 그리디하게 풀 수 있음
// 가방 크기 작은것 부터 최대 가치로 채워주기
// 가방 작은거 부터 큐에 넣어 가면서 하면 되지 않나?
//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using LL = long long;
//using LLpair = std::pair<LL, LL>;	//mass, value
//
//
//LLpair jewels[300000];
//LL bags[300000];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n, m;
//	std::cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> jewels[i].first >> jewels[i].second;
//	}
//
//	for (int i = 0; i < m; i++) {
//		std::cin >> bags[i];
//	}
//
//	std::sort(jewels, jewels + n);
//	std::sort(bags, bags + m);
//
//
//	std::priority_queue < LLpair, std::vector<LLpair>, bool(*)(const LLpair&, const LLpair&) > 
//		pq ([](const LLpair& a, const LLpair& b) { return a.second < b.second; });
//
//	LL fr = 0, ans = 0;
//	for (int i = 0; i < m; i++) {
//		while (fr < n && bags[i] >= jewels[fr].first) pq.push(jewels[fr++]);
//		if (pq.empty()) continue;
//
//		ans += pq.top().second;
//		pq.pop();
//	}
//
//	std::cout << ans;
//	return 0;
//}


//// 행렬 곱셉 순서
//
//#include <iostream>
//
//int matrix[500][2], n;
//int dp[500][500]; // dp[i][j] : i~j까지 행렬 곱셈 횟수의 최소값
//
//unsigned int dfs(int st, int en) {
//	if (st == en || dp[st][en]) return dp[st][en];
//
//	unsigned int min = (1U << 31);
//	for (int i = st; i < en; i++) {
//		min = std::min(min, dfs(st, i) + dfs(i + 1, en) + matrix[st][0] * matrix[i][1] * matrix[en][1]);
//	}
//
//	return dp[st][en] = min;
//}
//
//int main() {
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> matrix[i][0] >> matrix[i][1];
//	}
//
//	for (int i = 0; i < n - 1; i++) {
//		dp[i][i + 1] = matrix[i][0] * matrix[i][1] * matrix[i + 1][1];
//
//	}
//
//	dfs(0, n-1);
//
//	std::cout << dp[0][n-1];
//
//	return 0;
//}


// 부분 수열의 합2
//
//#include <iostream>
//#include <vector>
//
//// 숫자들에  20000000을 더함
//#define ZERO 2000000
//
//int dp[2][4000001];
//int main() {
//	int n, m;
//	std::cin >> n >> m;
//
//	for (int i = 0, num; i < n; i++) {
//		std::cin >> num;
//
//		for (int k = 0; k <= 4000000; k++) {
//			dp[(i + 1) % 2][k] = dp[i % 2][k];
//		}
//
//		for (int k = 0; k <= 4000000; k++) {
//			if (k + num < 0 || k + num > 4000000) continue;
//			dp[(i + 1) % 2][k + num] += dp[i % 2][k];
//		}
//		dp[(i + 1) % 2][num + ZERO] += 1;
//
//	}
//
//	//std::cout << dp[n % 2][ZERO - 1] << ' ' << dp[n % 2][ZERO] << ' ' << dp[n % 2][ZERO + 1];
//	std::cout << dp[n % 2][m + ZERO];
//
//	return 0;
//}


// 열쇠

//#include <iostream>
//#include <queue>
//#include <vector>
//
//using intpair = std::pair<int, int>;
//
//int dx[4] = { 0, 1, 0 ,-1 }, dy[4] = { 1, 0, -1, 0 };
//char map[102][102];
//
//bool keyHas[26];
//std::vector<intpair> doors[26];
//
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int tc;
//	std::cin >> tc;
//
//	while (tc--) {
//		int n, m;
//		std::cin >> n >> m;
//
//		for (int i = 1; i <= n; i++) {
//			std::cin >> map[i]+1;
//		}
//
//		char keys[27];
//		std::cin >> keys;
//		if (keys[0] != '0') {
//			for (int i = 0; keys[i]; i++) {
//				keyHas[keys[i] - 'a'] = true;
//			}
//		}
//
//		std::queue<intpair> que;
//		que.push({ 0,0 });
//		map[0][0] = '*';
//
//		int ans = 0;
//		while (!que.empty()) {
//			intpair cur = que.front();
//			que.pop();
//
//			for (int i = 0; i < 4; i++) {
//				int nx = cur.first + dx[i], ny = cur.second + dy[i];
//
//				if (nx > m + 1 || nx < 0 || ny > n + 1 || ny < 0) continue;
//				if (map[ny][nx] == '*') continue;
//
//				if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z' && !keyHas[map[ny][nx] - 'A']) {
//					doors[map[ny][nx] - 'A'].push_back({ nx, ny });
//				}
//				else {
//					if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z') {
//						for (intpair i : doors[map[ny][nx] - 'a']) {
//							que.push(i);
//						}
//						keyHas[map[ny][nx] - 'a'] = true;
//					}
//					else if (map[ny][nx] == '$') {
//						ans += 1;
//					}
//
//					que.push({ nx, ny });
//					map[ny][nx] = '*';
//				}
//			}
//
//
//		}
//
//		std::cout << ans << '\n';
//
//		for (int i = 0; i < 26; i++) {
//			doors[i].clear();
//			keyHas[i] = false;
//		}
//
//		for (int i = 0; i <= n + 1; i++) {
//			for (int k = 0; k <= m + 1; k++) {
//				map[i][k] = 0;
//			}
//		}
//	}
//
//	return 0;
//}
