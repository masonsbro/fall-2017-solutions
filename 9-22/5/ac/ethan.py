n = int(raw_input())

ans = 0
side = 1
while side * side <= n:
    if n % side == 0:
        ans += 1
    side += 1

print ans
