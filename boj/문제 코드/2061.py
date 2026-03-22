n, l = map(int, input().split())

ans = True
t = -1
for d in range(2, l) :
    if n % d == 0 :
        ans = False
        t = d
        break

if ans :
    print("GOOD")
else :
    print("BAD", t)