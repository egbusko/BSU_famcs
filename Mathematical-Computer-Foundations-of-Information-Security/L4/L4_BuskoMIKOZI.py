import sys

p = 882493304303057
q = 565640080106113
n = p * q
e = 435510454193522616856570224823
X1 = 33938304564942541056706890572
Y2 = 167669363821217143128176537107


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def egcd(a, b):
    if a == 0:
        return b, 0, 1
    d, x, y = egcd(b % a, a)
    return d, y - (b // a) * x, x


def Gen(p, q, e):
    fi = (p - 1) * (q - 1)
    if gcd(e, fi) != 1:
        return
    else:
        _, x, _ = egcd(e, fi)
        return x % fi


def binpow(a, n, z):
    res = 1
    while n:
        if n & 1:
            res = res * a % z
        a = a * a % z
        n >>= 1
    return res


def Encr(X, e, n):
    if X < 0 or X > n - 1:
        return
    else:
        return pow(X, e, n)


def Decr(Y, d, n):
    if Y < 0 or Y > n - 1:
        return
    else:
        return pow(Y, d, n)


with open("Report.txt", "w", encoding="utf-8") as file:
    d = Gen(p, q, e)
    file.write("Private key d = " + str(d) + "\n\n")

    Y1 = Encr(X1, e, n)
    file.write("Message   X1 = " + str(X1) + "\n" + "          Y1 = " + str(Y1) + "\n")
    file.write("Decrypted Y1 = " + str(Decr(Y1, d, n)) + "\n\n")

    X2 = Decr(Y2, d, n)
    file.write("Y2 = " + str(Y2) + "\n" + "X2 = " + str(X2) + "\n")


# while True:
#     resp = input("Gen, Encr, Decr, Exit: ")
#     if resp == 'Gen':
#         m, n, k = map(int, input("Enter p, q, e: ").split())
#         print(Gen(m, n, k))
#
#     if resp == 'Encr':
#         m, n, k = map(int, input("Enter X, e, n: ").split())
#         print(Encr(m, n, k))
#
#     if resp == 'Decr':
#         m, n, k = map(int, input("Enter Y, d, n: ").split())
#         print(Decr(m, n, k))
#
#     if resp == 'Exit':
#         sys.exit(0)
