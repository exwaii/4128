n = 1000000000
# print(n)

lp = [i for i in range(n + 1)]
for i in range(2, n + 1):
    if lp[i] == i:
        print(i)
        for j in range(i * i, n + 1, i):
            if lp[j] == j:
                lp[j] = i