def binary_exponentiation(base, exponent, mod):
    result = 1
    base %= mod

    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % mod
        exponent //= 2
        base = (base * base) % mod

    return result

def check(a, b, n):
    t1 = binary_exponentiation(a, b, float('inf')) - 1
    if t1 // (a - 1) >= n:
        return True
    else:
        return False

def check1(a, b, n):
    t1 = binary_exponentiation(a, b, float('inf')) - 1
    if t1 // (a - 1) == n:
        return True
    else:
        return False

t = int(input())
for _ in range(t):
    n = int(input())
    flag = 0
    for i in range(3, 26):
        l, r = 2, n + 1
        while r - l > 1:
            m = (r + l) // 2
            if check(m, i, n):
                r = m
            else:
                l = m + 1
        if check1(l, i, n):
            flag = 1
            break
        if check1(r, i, n):
            flag = 1
            break

    if flag == 1:
        print("YES")
    else:
        print("NO")
