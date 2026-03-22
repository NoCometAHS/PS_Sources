//// 변수 이름 / 개행
//// 구현 / 논리 /명세
//// 구현은 간단히 -> 구체적으로
//// 먼저 생각하기
//
//// dfs
//
//#include <iostream>
//
//bool r[9][10], c[9][10], box[9][10];
//int sudoku[9][9];
//
//int box_pos(int x, int y) {
//	return x / 3 + (y / 3) * 3;
//}
//
//bool dfs(int pos = 0) {
//	if (pos == 81) {
//		for (int i = 0; i < 9; i++) {
//			for (int k = 0; k < 9; k++) {
//				std::cout << sudoku[i][k];
//			}std::cout << '\n';
//		}
//		return true;
//	}
//
//	int x = pos % 9, y = pos / 9;
//
//	if (sudoku[y][x]) {
//		return dfs(pos + 1);
//	}
//
//	for (int i = 1; i < 10; i++) {
//		if (r[y][i] || c[x][i] || box[box_pos(x, y)][i]) continue;
//
//		sudoku[y][x] = i;
//		box[box_pos(x, y)][i] = c[x][i] = r[y][i] = true;
//
//		if (dfs(pos + 1)) {
//			return true;
//		}
//
//		sudoku[y][x] = 0;
//		box[box_pos(x, y)][i] = c[x][i] = r[y][i] = false;
//	}
//
//	return false;
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//	char row[10];
//
//	for (int i = 0; i < 9; i++) {
//		std::cin >> row;
//		for (int k = 0; k < 9; k++) {
//			 sudoku[i][k] = row[k]-'0';
//			if (!sudoku[i][k]) continue;
//
//			box[box_pos(k,i)][sudoku[i][k]] = c[k][sudoku[i][k]] = r[i][sudoku[i][k]] = true;
//		}
//	}
//
//	dfs();
//	return 0;
//}