#Bignum go brr
#Before doing a simple dp, I was doing a recursion, no memoisation, n^2 for n = 1000
#Only after a literal stack overflow, I changed the method to this O(n)
#Years of academy training wasted!
#0.03s
import math

def nodig(n):
    return len(str(n))

ans = 0 
last = (1, 2)

for i in range(1, 1001):
    sus1, jos1 = last
    sus2 = jos1
    jos2 = 2 * jos1 + sus1
    d = math.gcd(sus2, jos2)
    sus2 = sus2 // d
    jos2 = jos2 // d
    aux2 = sus2 + jos2 
    if nodig(aux2) > nodig(jos2):
        ans = ans + 1
    last = (sus2, jos2)
    
print(ans)
