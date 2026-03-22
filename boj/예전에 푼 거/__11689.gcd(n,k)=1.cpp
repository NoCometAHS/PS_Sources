// 변수 이름 + 개행
// 논리 / 구현 명세
// 구현은 간단히 -> 구체적
// 먼저 생각하기

// 정수론(오일러 피 함수), 소인수분해
// φ(p) = p-1 (p is prime)
// φ(p^n) = p^n-1 * (p-1)
// φ(p1^n1 * p2^n2) = φ(p1^n1) * φ(p2^n2)
//
//
// 분할 정복 제곱
// (? 시간 초과, 소수가 겁나 크면 다음 소수를 못 찾는데 느려)
// 
// + 에라토스테네스의 체
// [1,10^6]
// 10^6이하의 소수로 나누어 떨어지지 않는 수 t는
// 다음 소수 10^6+3과 곱하면 10^12를 넘어가기 때문에 t는 항상 소수이다
//// 
////
//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using LL = long long;
//
//LL myPow(LL a, LL b) {
//	if (b == 0) {
//		return 1;
//	}
//	if (b == 1) {
//		return a;
//	}
//
//	LL ret = myPow(a, b / 2);
//
//	if (b % 2) {
//		return ret * ret * a;
//	}
//	else {
//		return ret * ret;
//	}
//}
//
//bool isPrime(LL num) {
//	LL end = sqrt(num);
//
//	for (int i = 2; i <= end; i++) {
//		if (num % i == 0) return false;
//	}
//
//	return true;
//}
//
//
//std::vector<LL> primes;
//bool sieve[1000000];
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	
//	LL n;
//	std::cin >> n;
//
//	for (LL i = 2; i <= 100; i++) {
//		if (!isPrime(i)) continue;
//
//		for (LL k = 2; i * k < 1000000; k++) {
//			sieve[i * k] = true;
//		}
//	}
//	primes.reserve(50000);
//	for (int i = 2; i < 1000000; i++) {
//		if (sieve[i]) continue;
//		primes.push_back(i);
//	}
//
//	LL cnt, ans = 1;
//	for (const LL& i : primes) {
//		if (n == 1) break;
//		if (n % i) continue;
//		cnt = 0;
//
//		while (n % i == 0) {
//			cnt++;
//			n /= i;
//		}
//
//		ans *= myPow(i, cnt - 1) * (i - 1);
//	}
//
//	if (n != 1) ans *= n - 1;
//	std::cout << ans;
//
//	return 0;
//}

