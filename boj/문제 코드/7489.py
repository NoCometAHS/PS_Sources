import math

tc= int(input())

for _ in range(tc) :
    fact = math.factorial(int(input()))

    while fact % 10 == 0 :
        fact//=10
    
    print(int(fact % 10))

