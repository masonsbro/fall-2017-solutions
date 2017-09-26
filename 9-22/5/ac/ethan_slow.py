n = int(raw_input())

sizes = []
for x in range(1, n + 1):
    if n % x == 0:
        sizes.append((x, n / x))

dups = []
for i in range(len(sizes)):
    for j in range(i + 1, len(sizes)):
        if (sizes[i][0] == sizes[j][0] and sizes[i][1] == sizes[j][1]) or (sizes[i][0] == sizes[j][1] and sizes[i][1] == sizes[j][0]):
            dups.append(j)

print len(sizes) - len(dups)
