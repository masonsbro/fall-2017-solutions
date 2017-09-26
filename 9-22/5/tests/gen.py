import random

random.seed(13813561)

test_num = 0

def write_test(n):
    global test_num
    with open('input/input%02d.txt' % test_num, 'w') as f:
        f.write('%d\n' % n)
    with open('output/output%02d.txt' % test_num, 'w') as f:
        ans = 0
        side = 1
        while side * side <= n:
            if n % side == 0:
                ans += 1
            side += 1
        f.write('%d\n' % ans)
    test_num += 1

def gen_small():
    return random.randint(1, 1000000)

def gen_big():
    return random.randint(1000001, 1000000000000)

# Sample cases

write_test(51)
write_test(8)

# Small cases

write_test(1)
write_test(2)
write_test(4)
write_test(1000000)
write_test(999983)
write_test(999999)
for i in range(4):
    write_test(gen_small())

# Big cases

write_test(1000000000000)
for i in range(9):
    write_test(gen_big())
