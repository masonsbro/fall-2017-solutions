class BIT(object):

    def update(self, index, val):
        index += 1
        while index <= self.size:
            self.tree[index] += val
            index += index & (-index)

    def query(self, i):
        result = 0
        i += 1
        while i > 0:
            result += self.tree[i]
            i -= i & (-i)
        return result

    def __init__(self, size):
        self.size = size
        self.tree = [0] * (size + 1)


def read():
    r, k, d = map(int, input().strip().split())
    less = []
    greater = []
    for _ in range(r):
        a, s = map(int, input().strip().split())
        if a >= 18000:
            greater.append((a, s))
        elif a >= 12000:
            less.append((a, s))
    return less, greater, k, d


def checkAge(a, b, k):
    a, b = a[0], b[0]
    return min(a, b) >= ((max(a, b) // 2) - k)


def solve(people, k, d):
    people = sorted(people, key=lambda i: i[0], reverse=True)
    bit = BIT(100005)
    total = 0
    p2 = 0
    for p1 in range(len(people)):
        while p2 < len(people) and checkAge(people[p1], people[p2], k):
            bit.update(people[p2][1], 1)
            p2 += 1
        bit.update(people[p1][1], -1)
        total += bit.query(min(people[p1][1] + d, 100004))
        if people[p1][1] - d - 1 >= 0:
            total -= bit.query(people[p1][1] - d - 1)
    return total


def main():
    less, greater, k, d = read()
    total = solve(less, k, d) + solve(greater, k, d)
    print(total % 1000000007)


main()
