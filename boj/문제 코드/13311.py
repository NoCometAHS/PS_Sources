import math

ans = 1
i = 1
chk = [False for _ in range(1001)]
for i in range(2, 1001):
    if (chk[i]) : 
        continue

    k = i
    while (k + i < 1000) :
        chk[k] = True
        k += i
    ans *= k

print(str(ans - 1))


# n = a-1
# (a-1)*p = b-1 (mod b)

# (a-1)*p = q*b + b-1

# n = 1 (mod 2)
# n = 2 (mod 3)
# n = 3 (mod 4)

# 4 3 5
# 59
# 모듈러 연산은 따로 할 수 있으니깐

# n = 2*3...*1000 = 0 (mod 2..1000)
# 여기서 1빼면, 헉!
# 근데 너무 길어. 곱에 이미 포함되어 있는 수는 없어져도 답이 같은거 아닌가?

# 잠만 그냥 -1이면?