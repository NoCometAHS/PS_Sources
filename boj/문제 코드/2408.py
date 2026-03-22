n = int(input())

sik = input()

for _ in range((n-1)*2) :
    s = input()
    
    if (s == '/') :
        s += '/'
    
    sik += s

print(eval(sik))
