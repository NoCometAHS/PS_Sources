n = int(input())

arr = []
for _ in range(n):
    arr.append(float(input()))

cur = arr[0]
ans = arr[0]

for i in range(1,n):
    cur *= arr[i]

    if (cur < 1.0 or cur < arr[i]) :
        cur = arr[i]
    
    ans = max(ans, cur)

print(f"{ans:.3f}")
