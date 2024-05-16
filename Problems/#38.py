def check(ss):
    return sorted(ss) == sorted("123456789")

ans = ""
for i in range(1, 10000):
    s = ""
    for j in range(1, 6):
        s = s + str(i * j)
        if check(s):
            ans = max(ans, s)
print(ans)
