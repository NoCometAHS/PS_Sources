// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 모노톤 스택
// 일단 f(x) 전부 구하기
// 오른쪽 시작해서 f({Ai, pos}) 스택에 넣기
// //만약 top이 크면 그 수가 오등큰수
// //만약 top이 작으면 그거 빼버리기 (지금 오등큰수 찾고 있는 게 방금 버린 것보다 왼쪽에 있는 ai의 오등큰수가 되는게 맞음)

//#include <iostream>
//#include <stack>
//
//
//int cnt[1000001];
//int arr[1000000];
//int NGF[1000000];
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		std::cin >> arr[i];
//		cnt[arr[i]]++;
//	}
//
//	std::stack<int> st; //index
//
//	for (int i = n - 1; i >= 0; i--) {
//		while (!st.empty() && cnt[arr[i]] >= cnt[arr[st.top()]]) st.pop();
//
//		if (st.empty()) {
//			NGF[i] = -1;
//		}
//		else {
//			NGF[i] = arr[st.top()];
//		}
//
//		st.push(i);
//	}
//
//
//	for (int i = 0; i < n; i++) {
//		std::cout << NGF[i] << ' ';
//	}
//	return 0;
//}
