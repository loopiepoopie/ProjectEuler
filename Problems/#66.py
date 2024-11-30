#all information used for this can be found at
#https://en.wikipedia.org/wiki/Pell%27s_equation
#we meet again, continued fractions...
#execution time: 0.02s, better than the #64, just because I learnt that the period of 
#continued fraction of a square root is the length until twice the floor of the square root
#appears in the list
import math
def continued_frac(n): #computes the continued fraction for sqrt(n)
    rad = math.sqrt(n)
    imp = math.floor(rad)
    a = 1
    b = 0
    c = 1
    vec = []
    while 1:
        val = math.floor(a / c * rad + b / c)
        vec.append(val)
        if vec[-1] == 2 * imp:
            break
        na = a * c
        nb = val * c * c - b * c
        nc = a * a * n - b * b - val * val * c * c + 2 * b * val * c
        gcd = math.gcd(math.gcd(na, nb), nc)
        na //= gcd
        nb //= gcd
        nc //= gcd
        a = na
        b = nb
        c = nc
    return vec

def compute_frac(vec):
    a = 1
    b = vec[len(vec) - 1]

    for i in range(len(vec) - 2, -1, -1):
        sus = vec[i] * b + a
        jos = b
        gcd = math.gcd(sus, jos)
        sus //= gcd
        jos //= gcd
        a = jos
        b = sus
    return [b, a]

def get_sol(n):
    vec = continued_frac(n)
    if len(vec) % 2 == 1:
        vec = vec[:-1]
    else:
        vec = (vec + vec[1:])[:-1]
    return compute_frac(vec)

big_x = 0
ans = 0

for d in range(1, 1001):
    if math.sqrt(d) != math.floor(math.sqrt(d)):
        [a, b] = get_sol(d)
        if a > big_x:
            big_x = a
            ans = d
print(ans)
