// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

//
// 모노톤 스택
//
// stack<{int ,int}> // 그래프 크기, 그 크기로 이어진 개수
// 
// top이 지금 들어올 숫자보다 크다면, 그 크기로 이어진 개수 그 뒤 숫자에 더하고 배는거 거짓이 될때 까지 빼야함
// top이 지금 들어올 숫자보다 작다면, 일단 그냥 넣어 둬야지
// 
// 같다면 합쳐버리기
// 
// 마지막에 전부 빼면서 정리하면 될 듯
//
//
//#include <iostream>
//#include <stack>
//
//using intpair = std::pair<int, int>;
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//
//	std::stack<intpair> st;
//	int height, ans = 0;
//	while (n--) {
//		std::cin >> height;
//
//		int temp = 0;
//		while (!st.empty() && st.top().first >= height) {
//			st.top().second += temp;
//
//			ans = std::max(st.top().first * st.top().second, ans);
//
//			temp = st.top().second;
//			st.pop();
//		}
//
//		st.push({ height, temp + 1 });
//	}
//
//	int temp = 0;
//	while (!st.empty()) {
//		st.top().second += temp;
//
//		ans = std::max(st.top().first * st.top().second, ans);
//
//		temp = st.top().second;
//		st.pop();
//	}
//
//	std::cout << ans;
//	return 0;
//}