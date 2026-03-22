import sys

def ChangeNotation(num, cur, to):
    temp = 0
    t = 1
    while num:
        temp += num%10 * t
        num //= 10
        t *= cur

    ret = ""
    while temp:
        ret += str(temp % to)
        temp //= to

    if (ret == "") :
        return 0
    return int(ret[::-1])



while True:
    inputs = sys.stdin.readline().split()
    
    if (len(inputs) == 1):
        break
    b, p, m = map(int, inputs)
    print(ChangeNotation(ChangeNotation(p,b,10) % ChangeNotation(m,b,10), 10, b))
