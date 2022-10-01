import sys

p = 1044779951622553
q = 810317495045789
e = 657311140049004998195550456065
X1 = 543066057187844905915287549311
Y2 = 482438945755863228767362999535
n = p * q

# def binpow (a, n, z):   # use standard pow(x, y[, z]) ?
#     res = 1
#     while n:
#         if n & 1:
#             res = res * a % z
#         a = a * a % z
#         n >>= 1
#     return res

# "обычный" алгоритм Евклида
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

# расширенный алгоритм Евклида(исп-ся для получения обратного по модулю элемента)
def egcd (a, b):
    if a == 0:
        return b, 0, 1              # a*x + b*y = gcd(a, b)
    d, x, y = egcd(b % a, a)        # e*x + ф*y = gcd(e, ф) = 1     | % ф
    return d, y - (b // a) * x, x   # e*x = 1   -> e^-1

# генерация закрытого ключа d
def Gen(p, q, e):
    φ = (p - 1) * (q - 1)
    if gcd(e, φ) != 1:
        return
    else:
        _, x, _ = egcd(e,φ)
        return x % φ

# encryption
def Encr(X, e, n):
    if X < 0 or X > n - 1:
        return
    else:
        return pow(X, e, n)

# decryption
def Decr(Y, d, n):
    if Y < 0 or Y > n - 1:
        return
    else:
        return pow(Y, d, n)

with open("Report.txt", "w", encoding="utf-8") as file:
    d = Gen(p, q, e)
    file.write("d = " + str(d) + "\n")
    Y1 = Encr(X1, e, n)
    file.write("X1 = " + str(X1) + "\n" + "Y1 = " + str(Y1) + "\n")
    file.write("Decrypted Y1: " + str(Decr(Y1, d, n)) + "\n")
    X2 = Decr(Y2, d, n)
    file.write("Y2 = " + str(Y2) + "\n" + "X2 = " + str(X2) + "\n")

# while True:
#     resp = input("Gen, Encr, Decr, Exit: ")
#     if resp == 'Gen':
#         m, n, k = map(int, input("Input p, q, e: ").split()) 
#         print(Gen(m, n, k))
#     if resp == 'Encr':
#         m, n, k = map(int, input("Input X, e, n: ").split())
#         print(Encr(m, n, k))
#     if resp == 'Decr':
#         m, n, k = map(int, input("Input Y, d, n: ").split())
#         print(Decr(m, n, k))
#     if resp == 'Exit':
#         sys.exit(0)