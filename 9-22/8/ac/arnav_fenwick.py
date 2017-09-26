MOD = 1000000007
MAX_SALARY = 100005

def add(f_tree, index, delta):
    x = index
    while x < MAX_SALARY:
        f_tree[x] += delta
        x += (x & (-x))

def query(f_tree, index):
    ans = 0
    x = index
    while x > 0:
        ans += f_tree[x]
        x -= (x & (-x))

    return ans

def solve(people, k, d):
    if not people:
        return 0

    people.sort()
    n = len(people)

    # pointer to the youngest person whose age is still valid
    lower_ptr = 0

    ans = 0

    # Fenwick tree
    f_tree = [0] * MAX_SALARY

    add(f_tree, people[0][1], 1)

    # iterate over each person and figure out how many people before them they
    # can date.
    for i in range(1, n):
        age, salary = people[i]
        # increment the lower ptr to get in range
        while lower_ptr < i and people[lower_ptr][0] < (age // 2) - k:
            add(f_tree, people[lower_ptr][1], -1)
            lower_ptr += 1

        # Now that the ages are valid, find people with valid salaries

        min_salary = max(0, salary - d)
        max_salary = min(MAX_SALARY - 1, salary + d)

        ans += query(f_tree, max_salary)
        ans -= query(f_tree, min_salary - 1)

        # Add your salary to the fenwick tree
        add(f_tree, salary, 1)

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
