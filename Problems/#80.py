#I've decided to use long division to calculate each and every digit 
#it is lightning quick on Py3, only 0.01s :) 
import math
def get_digs(n): #this just finds the first 100 digits of sqrt(n) using long division
    vec = []
    floor = math.floor(math.sqrt(n))
    aux = n - floor * floor
    num = floor
    while floor != 0:
        vec.append(floor % 10)
        floor //= 10
    vec.reverse()
    while len(vec) < 100:
        aux *= 100
        aux2 = num * 2
        dig = -1
        for j in range(9, -1, -1):
            if (aux2 * 10 + j) * j <= aux:
                dig = j
                break
        vec.append(dig)
        aux -= (aux2 * 10 + dig) * dig
        num = num * 10 + dig
    return vec


ans = 0
for i in range(1, 101):
    if math.sqrt(i) != math.floor(math.sqrt(i)):
        ans += sum(get_digs(i))

print(ans)
