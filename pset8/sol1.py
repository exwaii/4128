from math import comb

n, m = map(int, input().split())

answer = 0
for i in range(int(n/m) + 1):
    answer += comb(n - i * (m - 1), i)
    # print(answer)
answer %= 1000000007
print(answer)