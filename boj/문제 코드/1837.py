sieve = [False for _ in range(1101010)]
primes = []

for i in range(2, 1101010):
    if (sieve[i]) :
        continue
    primes.append(i)

    for k in range(i*i, 1101010, i):
        sieve[k] = True

n, m = map(int, input().split())

for p in primes :
    if (p >= m) :
        print("GOOD")
        break

    if (n % p == 0) :
        print("BAD", p)
        break


