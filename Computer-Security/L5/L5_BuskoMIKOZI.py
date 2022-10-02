import sys
import random
import hashlib

q = 210697455032337684943121194039863591186004713463570796268765689709223108292419

# fast exponentiation modulo z
def binpow(a, n, z):
    res = 1
    while n:
        if n & 1:
            res = res * a % z
        a = a * a % z
        n >>= 1
    return res

# fast multiplication modulo z
def binmultiply(a, b, p):
    res = 0
    a = a % p
    while b:
        if b & 1:
            res = (res + a) % p
        a = (2 * a) % p
        b >>= 1
    return res

# extended Euclidean algorithm (used to obtain the inverse modulo the element)
def egcd(a, b):
    if a == 0:
        return b, 0, 1
    d, x, y = egcd(b % a, a)
    return d, y - (b // a) * x, x


def randRp(q):
    R = random.randint(0, 4 * (q + 1))
    R += R % 2
    p = q * R + 1
    return R, p


def Gen(q):
    R = 0
    p = 0
    g = 0
    while True:
        R, p = randRp(q)
        if (binpow(2, q * R, p) == 1) and (binpow(2, R, p) != 1):
            break
    while True:
        x = random.randint(0, p - 1)
        g = binpow(x, R, p)
        if g != 1:
            break
    d = random.randint(0, q - 1)
    e = binpow(g, d, p)
    return p, q, g, e, d


def Sign(p, q, g, d, M):
    m = int.from_bytes(hashlib.sha256(M).digest(), sys.byteorder)
    k = random.randint(1, q - 1)
    r = binpow(g, k, p)
    nod, x, _ = egcd(k, q)
    if nod != 1:
        raise Exception("k^-1 doesn't exist.")
    x %= q
    s = (x * (m - d * r)) % q
    return r, s


def Verify(p, q, g, e, M, r, s):
    if (r not in range(1, p - 1)) or (s not in range(0, q - 1)):
        return False
    m = int.from_bytes(hashlib.sha256(M).digest(), sys.byteorder)
    if binmultiply(binpow(e, r, p), binpow(r, s, p), p) == binpow(g, m, p):
        return True
    else:
        return False


with open("Report.txt", "w", encoding="utf-8") as file:
    M = b"I, Yegor Busko, like MiKOZI"
    p, q, g, e, d = Gen(q)
    file.write('M = ' + str(M.decode('utf-8')) + '\n\np = ' + str(p) +
               '\nq = ' + str(q) + '\ng = ' + str(g) + '\ne = ' + str(e) + '\nd = ' + str(d))
    r, s = Sign(p, q, g, d, M)
    file.write('\n\nr = ' + str(r) + '\ns = ' + str(s))
    file.write('\n\nResult : ' + str(Verify(p, q, g, e, M, r, s)))
