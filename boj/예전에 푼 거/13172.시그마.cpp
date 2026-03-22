// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 구현, 수학
// 분수 기약분수로 만들기
// pow로 b의 곱샘의 역원 구하기
// 기대값 표현
// 반복
// gcd, pow

// 페르마의 소정리 우마이!
// x = prime, a^x-1 = 1 (mod x)

//#include <iostream>
//
//#define BigPrime 1000000007LL
//
//using LL = unsigned long long;
//
//LL gcd(LL a, LL b) {
//	LL t;
//	while (a % b != 0) {
//		t = a % b;
//		a = b;
//		b = t;
//	}
//
//	return b;
//}
//
//LL pow_mod(LL a, LL n) {
//	if (n == 1) return a;
//
//	LL res = pow_mod(a, n/2);
//	res = (res * res) % BigPrime;
//
//	if (n % 2) {
//		return (res * a)%BigPrime;
//	}
//	else {
//		return res;
//	}
//}
//
//int main() {
//	int n;
//	std::cin >> n;
//
//	LL ans = 0;
//	while (n--) {
//		LL a, b;
//		std::cin >> a >> b;
//
//		LL ABGcd = gcd(a, b);
//		a /= ABGcd, b /= ABGcd;
//
//		LL fraction = (b * pow_mod(a, BigPrime - 2)) % BigPrime;
//
//		ans = (ans + fraction) % BigPrime;
//	}
//
//	std::cout << ans;
//	return 0;
//}