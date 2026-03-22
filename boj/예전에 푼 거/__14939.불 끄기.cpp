// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 버튼을 눌렀을 때 개수가 오히려 늘면 전부다 끄기 불가능 (x, 아닌 경우 있었음)
// 
// 백트레킹, 브루트 포스 (x, 백트레킹 하면 느려 터짐)
//
// 스위치 한번 만지면 그곳 누르는 것이 정답이라면 그 이후로 그곳 다시 만질 일 없음.
// // 누를 곳 전부 누른 한 경우의 수에서 누른 곳 2번 누르는 경우 없음. 2번 누른 건 누르지 않은 경우랑 같기 떄문
// 
// 왼쪽위에서 오른쪽아래로 가면서 하나씩 눌러보면서 보기
// 만약 자신의 위의 전구가 켜지게 되면 뒤로 돌아가기. 그 켜진 전구 끌 방법 없음.->왼쪽 스위치도 마찬가지인가(x)
// 
// -> 스위치 만질 전구의 위의 전구가 켜져 있는 것만 만질 거임
// 
// 구현
// 맨 최상위 줄만 정해지면 나머지는 뭘 눌러야하는지 정해짐
//// 위에 남아 있다면 현제 불 눌러서 끄기
//
//
// 왼쪽위에서 아래로 가면서 불을 끈다면 다음줄에서 무조건 위의 불을 꺼줘야해!
// 즉 가장 윗줄이 고정된다면 다른 줄들은 뭘 눌러야하는지 정해져!
// 라는 생각처럼 문제를 쉽게 풀 수 있도록 해석하는 능력이 중요함
//


/*
OOOOOOOOO#
#O##O##O##
##########
##########
##########
##########
##########
##########
##########
##########
*/
//#include <iostream>
//
//using intpair = std::pair<int, int>;
//bool map[100], temp[100];
//int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
//
//int turn_off_light() {
//	int cnt = 0;
//
//	for (int i = 0; i < 100; i++) temp[i] = map[i];
//
//	for (int y = 1; y < 10; y++) {
//		for (int x = 0; x < 10; x++) {
//			if (!temp[(y - 1) * 10 + x]) continue;
//			
//			cnt++;
//			
//			temp[y*10 + x] = !temp[y*10 + x];
//			for (int k = 0; k < 4; k++) {
//				int nx = x + dx[k], ny = y + dy[k];
//				if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
//
//				temp[ny * 10 + nx] = !temp[ny * 10 + nx];
//			}
//		}
//	}
//
//	/*for (int i = 0; i < 100; i++) {
//		std::cout << temp[i];
//
//		if ((i + 1) % 10 == 0)std::cout << '\n';
//	}
//	system("pause");*/
//
//
//	bool flag = false;
//	for (int i = 0; !flag && i < 10; i++) {
//		flag = temp[90 + i];
//	}
//	//std::cout << flag << "\n\n";
//	return (flag ? 1e9 : cnt);
//}
//
//int dfs(int idx = 0, int lv = 1) {
//	if (idx == 10) return 1e9;
//
//	int ret = 1e9;
//	
//	for (int i = idx; i < 10; i++) {
//
//		map[i] = !map[i];
//		for (int k = 0; k < 4; k++) {
//			int nx = i + dx[k], ny = dy[k];
//			if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
//
//			map[ny * 10 + nx] = !map[ny * 10 + nx];
//		}
//
//		//std::cout << "_____________________________________\n";
//		//for (int i = 0; i < 100; i++) {
//		//	std::cout << map[i];
//
//		//	if ((i + 1) % 10 == 0)std::cout << '\n';
//		//}
//		//std::cout << "-------------------------------------------\n";
//
//		ret = std::min({ ret, turn_off_light() + lv, dfs(i + 1, lv + 1) });
//
//		map[i] = !map[i];
//		for (int k = 0; k < 4; k++) {
//			int nx = i + dx[k], ny = dy[k];
//			if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
//
//			map[ny * 10 + nx] = !map[ny * 10 + nx];
//		}
//	}
//
//	return ret;
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	char ch;
//	for (int i = 0; i < 10; i++) {
//		for (int k = 0; k < 10; k++) {
//			std::cin >> ch;
//			map[i * 10 + k] = ch == 'O';
//		}
//	}
//
//	int ans = turn_off_light();
//	ans = std::min(ans, dfs());
//
//	std::cout << (ans < 1e9 ? ans : -1);
//	return 0;
//}