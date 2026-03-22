import math

n, m, cnt = map(int, input().split())

arr = [0 for _ in range(n+1)]
for _ in range(m-1) :
    a, b, c = map(int, input().split())
    arr[a] += 1
    arr[b] += 1
    arr[c] += 1


ans = [0,0,0]
pa = 1
ch = 0

for a in range(1, n+1):
    for b in range(a+1, n+1):
        for c in range(b+1, n+1) :
            sum = arr[a] + arr[b] + arr[c] + 3
            
            par = 3*m
            child = par - sum

            par = par**(cnt+1)
            child = child**cnt * sum

            res = math.gcd(par, child)
            par //= res
            child //= res

            if ch*par < child*pa :
                ch = child
                pa = par

                ans[0] = a
                ans[1] = b
                ans[2] = c

print(ch, pa)
print(ans[0],ans[1],ans[2])

            
            
