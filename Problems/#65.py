##cute "fun fact" problem
##I decided python was a good choice, because the result may be a long integer and it turned out to be one
##0.01s
##as ideas for the problem, you computed the fraction from bottom to top, I did iteratively
import math

def sumdig(n):
    ans = 0
    while n != 0:
        ans = ans + n % 10
        n = n // 10
    return ans
vec = [2]
n = 100

for i in range(1, n + 1):
    dig = 0
    if i % 3 == 2:
        dig = ((i - 2) // 3 + 1) * 2
    else:
        dig = 1
    vec.append(dig)
##print(vec)

sus = 0
jos = 1
for i in range(n, -1, -1):
    s1 = sus * vec[i] + jos
    s2 = sus
    d = math.gcd(s1, s2)
    s1 = s1 // d
    s2 = s2 // d
    sus = s1
    jos = s2

print(sumdig(sus))
