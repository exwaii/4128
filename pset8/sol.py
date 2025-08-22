n = int(input())

a = list(map(int, input().split()))
lp = [i for i in range(max(a) + 1)]
for i in range(2, max(a) + 1):
    if lp[i] == i:
        for j in range(i * i, max(a) + 1, i):
            if lp[j] == j:
                lp[j] = i


def factors(x):
    res = set()
    while x > 1:
        res.add(lp[x])
        x /= lp[x]
        x = int(x)
    return sorted(list(res))

def gcd(a, b):
    return gcd(b, a % b) if b > 0 else a 

def check(i):
    l = factors(i)
    for j in range(len(l)):
        for k in range(j + 1, len(l)):
            d1 = l[j]
            d2 = l[k]
            if gcd(d1 + d2, i) == 1:
                return (d1, d2)
    # for d1 in factors(i):
    #     for d2 in factors(i):
            
            
    return (-1, -1)

first = [0 for i in range(n)]
second = [0 for i in range(n)]

for i in range(n):
    res = check(a[i])
    # if res[0] == -1:
    #     print(a[i])
    first[i] = min(res)
    second[i] = max(res)
    
print(' '.join(map(str, first)))
print(' '.join(map(str, second)))