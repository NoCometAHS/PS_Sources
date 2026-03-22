n = int(input())

a = pow(2, n)
b = pow(10, n)


print("0.", "0"*(n - len(str(b//a))), b//a, sep='')