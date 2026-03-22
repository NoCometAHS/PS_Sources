////
//// 수학, 날짜 계산
//// 시간들 전부다 초로 변환
//// 
////
//
//#include <iostream>
//#include <cmath>
//
//
//#pragma warning (disable : 4996)
//
//int dates[1000][6];
//int seconds[1000];
//int difficulty[1000];
//
//int dayLimit[2][13] = {
//	{0, 31, 28, 31, 30, 31, 30, 31, 31,30, 31,30, 31},
//	{0, 31, 29, 31, 30, 31, 30, 31, 31,30, 31,30, 31},
//};
//
//int main() {
////	for (int i = 1; i < 13; i++) {	//누적합
////		dayCnt[0][i] = dayCnt[0][i - 1];
////		dayCnt[1][i] = dayCnt[1][i - 1];
////	}
//
//	int n;
//	scanf("%d", &n)
//	for (int i = 0; i < n; i++) {
//		scanf("%d/%d/%d %d:%d:%d %d", dates[i], dates[i] + 1, dates[i] + 2, dates[i] + 3, dates[i] + 4, dates[i] + 5, difficulty+i);
//	}
//
//	for (int i = 0; i < n; i++) {
//		int curY = 2019, curM = 6, curD = 6, dayCnt = 0;
//		bool leapYear = false;
//
//		while (curY != dates[i][0] || curM != dates[i][1] || curD != dates[i][2]) {
//			dayCnt++;
//			curD++;
//
//			if (curD > dayLimit[leapYear][curM]) {
//				curD = 1;
//				curM++;
//
//				if (curM <= 12) continue;
//
//				curM = 1;
//				curY++;
//				leapYear = (curY == 2020);
//			}
//		}
//
//		seconds[i] = dayCnt * 24 * 60 * 60 + dates[i][3]*60*60 + dates[i][4]*60 + dates[i][5];
//	}
//	
//	int oneYearSec = 365 * 24 * 60 * 60;
//
//
//	double child = 0, par = 0;
//	for (int i = 0; i < n; i++) {
//		double p = std::max(std::pow(0.5, ((double)seconds[n - 1] - seconds[i]) / oneYearSec), std::pow(0.9, n - i - 1));
//		child += p * difficulty[i];
//		par += p;
//	}
//
//	if (par != 0) {
//		std::cout << std::round(child / par);
//	}
//	else {
//		std::cout << 0;
//	}
//
//	return 0;
//}