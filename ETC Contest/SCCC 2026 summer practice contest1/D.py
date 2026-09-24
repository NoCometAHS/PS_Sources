m = int(1e9+7)

n = int(input())
arr = map(int, input().split())

cur = 1
fail = False
for needed in arr:
    cur = cur * 2
    
    if (cur < needed):
        fail=True
        break
    
    cur -= needed
    
if fail :
    print("error")
else :
    print(cur % m)
