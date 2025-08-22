from random import randint

# print(f"{randint(1, 100000)} {randint(2, 100)}")
n = 2
print(n)

# lp = [i for i in range(n + 1)]
# for i in range(2, n + 1):
#     if lp[i] == i:
#         for j in range(i * i, n + 1, i):
#             if lp[j] == j:
#                 lp[j] = i


# def factors(x):
#     res = set()
#     while x > 1:
#         res.add(lp[x])
#         x /= lp[x]
#         x = int(x)
#     return res

# count = 0
# count += 1
# a = []
# print(len(a))

for i in range(n):
    # if len(factors(i)) > 1:
    #     a.append(i)
    if i != n:
        print(randint(1, 10000000), end=' ')
    else:
        print(randint(1, 10000000), end='')
print()

# print(' '.join(map(str, a)))
