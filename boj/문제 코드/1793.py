dp = [0 for _ in range(250+1)]

dp[0] = 1
dp[1] = 1
dp[2] = 3

for i in range(3, 250+1):
    dp[i] = dp[i - 1] + dp[i-2] * 2

while True:
    try:
        n = int(input())
        print(dp[n])
    except:
        break


