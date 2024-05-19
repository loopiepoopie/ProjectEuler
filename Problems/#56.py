#These brute force algorithms take way too little time. 
#0.16s 
def sumofdig(n):
    ans = 0
    s = str(n)
    for x in s:
        ans = ans + int(x)
    return ans

ans = 0;
for i in range(1, 100):
    for j in range(1, 100):
        ans = max(ans, sumofdig(i ** j))
print(ans)
