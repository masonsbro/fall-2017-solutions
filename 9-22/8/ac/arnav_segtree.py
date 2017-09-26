MOD = 1000000007
MAX_SALARY = 100005
IDENTITY = 0

class SegTree(object):
    @staticmethod
    def combine(a, b):
        return a + b

    def __init__(self, l, r, a):
        self.l = l
        self.r = r
        if l == r:
            self.value = a[l]
        else:
            mid = (l + r) // 2
            self.left_child = SegTree(l, mid, a)
            self.right_child = SegTree(mid + 1, r, a)

            self.value = self.combine(self.left_child.value, self.right_child.value)

    def query(self, ql, qr):
        # check if in bounds
        if qr < self.l or ql > self.r:
            return IDENTITY

        # check if fully contained
        if ql == self.l and qr == self.r:
            return self.value

        mid = (self.l + self.r) // 2
        a = self.left_child.query(ql, min(qr, mid))
        b = self.right_child.query(max(ql, mid + 1), qr)

        return self.combine(a, b)

    def update(self, index, value):
        if self.l == self.r:
            self.value += value
        else:
            mid = (self.l + self.r) // 2
            if index <= mid:
                self.left_child.update(index, value)
            else:
                self.right_child.update(index, value)

            self.value = self.combine(self.left_child.value, self.right_child.value)

def solve(people, k, d):
    if not people:
        return 0

    people.sort()
    n = len(people)

    # pointer to the youngest person whose age is still valid
    lower_ptr = 0

    ans = 0

    # Segment Tree
    seg_tree = SegTree(0, MAX_SALARY - 1, [0] * MAX_SALARY)

    seg_tree.update(people[0][1], 1)

    # iterate over each person and figure out how many people before them they
    # can date.
    for i in range(1, n):
        age, salary = people[i]
        # increment the lower ptr to get in range
        while lower_ptr < i and people[lower_ptr][0] < (age // 2) - k:
            seg_tree.update(people[lower_ptr][1], -1)
            lower_ptr += 1

        # Now that the ages are valid, find people with valid salaries

        min_salary = max(0, salary - d)
        max_salary = min(MAX_SALARY - 1, salary + d)

        ans += seg_tree.query(min_salary, max_salary)

        # Add your salary to the fenwick tree
        seg_tree.update(salary, 1)

    return ans % MOD

def main():
    n, k, d = map(int, input().split())

    teens = []
    adults = []
    for _ in range(n):
        age, salary = map(int, input().split())

        # Shouldn't matter, and makes fenwick tree easier
        salary += 1

        if age < 12000:
            continue
        if age < 18000:
            teens.append((age, salary))
        else:
            adults.append((age, salary))

    ans = solve(teens, k, d) + solve(adults, k, d)
    print(ans)

main()
