//
// 분리된 서로다른 두 그래프를 연결 할 수 있다.
// 
// 사이클이 없는 그래프끼리 합쳐서 하나의 그래프로 만들 수 없음
// 사이클 개수가 중요
// 
// 사이클 + 사이클 = 사이클
// 사이클 + 다른 그래프 = 사이클 아님
// 
// x자 연결 =자 연결 구분이 필요 없는 것 같은데
// 
// 다른 종류의 구성원을 가진 사이클의 개수 > 일반 그래프 개수 : 불가능
// else "일반 그래프 개수" 번 연결해야함
// 
// 백트레킹?, u&f, dfs
// 간선 하나하나 선택해가면서 백트레킹
// // 만약 그래프 개수가 줄지 않는 다면 뒤로 돌아가기
// // 그래프 개수는 dfs로 확인 + 이때 u&f다시 만들어 줌
// 
// 헉!!!!!!!!!!
//
// 사이클로 보지말고 간선의 개수로 봐보자 (그래프에서 노드가n개이상 있다는 말은 어딘가에 사이클이 존재한다는 의미)
// a(3, 4) -> 그래프a(노드 수, 간선 수)
// a(4, 5) + b(3, 2) -> ab(7, 7) 따라서 어딘가에 연결해도 끊기지 않을 간선이 존재
// 
// 그리디, dfs
// 
// 연결할 수 있으면 연결하는게 최고
//
///*
//
//NYYNN
//YNYNN
//YYNNN
//NNNNY
//NNNYN
//
//NYYNN
//YNYNY
//YNNYN
//NNYNN
//NYNNN
//4
//1 2
//1 3
//2 3
//4 5
//
//반례)
//2 1
//4 6
//1 0
//-> 7 7 하지만 한개로 만들지 못 함
//7
//1->2
//2->1
//3->456
//4->356
//5->346
//6->345
//7
//NYNNNNN
//YNNNNNN
//NNNYYYN
//NNYNYYN
//NNYYNYN
//NNYYYNN
//NNNNNNN
//*/
//
//#include <iostream>
//#include <stack>
//
//using intpair = std::pair<int, int>;
//
//
//intpair graphInfo[50]; //nodeCnt, edgeCnt
//int setTree[50];
//
//
//int find_par(int cur) {
//	if (cur == setTree[cur]) return cur;
//	else return setTree[cur] = find_par(setTree[cur]);
//}
//
//void union_set(int a, int b) {
//	a = find_par(a), b = find_par(b);
//
//	graphInfo[a].first += graphInfo[b].first;
//	graphInfo[a].second += graphInfo[b].second;
//
//	setTree[b] = a;
//
//	return;
//}
//
//
//int main(){
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		setTree[i] = i;
//		graphInfo[i].first = 1;
//	}
//
//	int graphCnt = 0, edgeCnt = 0;
//	char ch;
//	for (int i = 0; i < n; i++) {
//		for (int k = 0; k < n; k++) {
//			std::cin >> ch;
//			if (k <= i || ch == 'N') continue;
//
//			int ipar = find_par(i), kpar = find_par(k);
//
//			if (ipar != kpar) {
//				union_set(ipar, kpar);
//				//std::cout << ipar << ' ' << kpar << '\n';
//			}
//			
//			graphInfo[ipar].second++;
//		}
//	}
//
//	bool chkk[50] = { false, };
//
//	//for (int i = 0; i < n; i++) {
//	//	int p = find_par(i);
//	//	
//	//	if (chkk[p]) continue;
//	//	
//	//	chkk[p] = true;
//
//
//	//	std::cout << graphInfo[p].first << ' ' << graphInfo[p].second << '\n';
//	//}std::cout << "------------\n";
//
//
//	std::stack<int> st;
//
//	bool chk[50] = { false, }, flag = true;
//
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		int par = find_par(i);
//		if (chk[par]) continue;
//
//		chk[par] = true;
//		
//		if (graphInfo[par].second == 0) {
//			flag = (false || n == 1);
//
//			break;
//		}
//
//		while ( !st.empty() && (graphInfo[par].first <= graphInfo[par].second || graphInfo[st.top()].first <= graphInfo[st.top()].second)) {
//			union_set(par, st.top());
//			st.pop();
//
//			ans++;
//		}
//
//		st.push(par);
//	}
//
//
//	std::cout << (st.size() <= 1 && flag ? ans : -1);
//
//	return 0;
//}
//
//
//
//
//
//
