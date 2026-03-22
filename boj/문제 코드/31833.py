n = int(input())

x = ''
a = input().split()
for i in a:
    x += i

y = ''
a = input().split()
for i in a:
    y += i

if int(x) > int(y) :
    print(y)
else :
    print(x)
