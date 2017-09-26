from collections import defaultdict

t = int(raw_input())
assert 1 <= t <= 10

for qq in range(t):
    n, l = map(int, raw_input().split())
    assert 1 <= n <= 100000
    assert 1 <= l <= 100000
    num_laps = defaultdict(lambda: 0)
    finishers = []
    for i in range(n):
        name = raw_input()
        num_laps[name] += 1
        if num_laps[name] == l:
            finishers.append(name)
    if len(finishers) >= 2:
        print finishers[0]
        print finishers[1]
    else:
        print 'Armageddon'
