n = int(input())
s = set()
f = set()
for _ in range(n):
    a, b = input().strip().split()
    if a == 's':
        s.add(b)
    else:
        f.add(b)
print(len(s & f))
