#Surprisingly, 0.15s 
def reverse(i):
    s = str(i)
    return int(s[::-1])

def ispal(i):
    return i == reverse(i)

ans = 0
for i in range(1, 10001):
    aux = i
    done = 0
    for j in range(1, 51):
        aux = aux + reverse(aux)
        if ispal(aux):
            done = 1
            break
    if not(done):
        ans = ans + 1
print(ans)
            
