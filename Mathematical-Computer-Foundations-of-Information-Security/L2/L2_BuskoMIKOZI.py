X = 28
k = 3986
n = 8

handle = open("Result.txt", "w")

print("X = " + str(X) + " = " + str(bin(X)[2:]))
handle.write("X = " + str(X) + " = " + str(bin(X)[2:]) + "\n")
print("k = " + str(k) + " = " + str(bin(k)[2:]) + "\n")
handle.write("k = " + str(k) + " = " + str(bin(k)[2:]) + "\n")


def split_str(cpyStr):
    half = len(cpyStr) // 2
    return str(int(cpyStr[:half], 2)), str(int(cpyStr[half:], 2))


def fill_str(string):
    while len(string) != 4:
        string = "0" + string
    return string


S1 = dict(zip("0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15".split(),
              "14 7 10 12 13 1 3 9 0 2 11 4 15 8 5 6".split()))
S2 = dict(zip("0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15".split(),
              "9 6 3 2 8 11 1 7 10 4 14 15 12 0 13 5".split()))

key = dict(zip("1 2 3 4 5 6 7 8 9 10 11 12".split(), str(bin(k)[2:])))

R1 = "10 12 2 5 8 6 9 4".split()
R2 = "2 9 10 5 1 12 6 4".split()
R3 = "7 1 2 6 12 3 9 11".split()

P = "1 4 7 2 5 8 3 6".split()
k1 = k2 = k3 = ""

for i in range(0, n):
    k1 += key[R1[i]]
    k2 += key[R2[i]]
    k3 += key[R3[i]]

K = [int(k1, 2), int(k2, 2), int(k3, 2)]

for i in range(0, len(K)):
    print("k" + str(i + 1) + " = ", str(bin(K[i])[2:]))

for item in K:
    tmp = str(bin(X + item))[2:]

    if (len(tmp) > 8):
        offset = len(tmp) % 8
        T1, T2 = split_str(tmp[offset:])
    else:
        T1, T2 = split_str(tmp[0:])

    N1 = str(bin(int(S1[T1])))[2:]
    N2 = str(bin(int(S2[T2])))[2:]
    if len(N1) < 4:
        N1 = fill_str(N1)
    if len(N2) < 4:
        N2 = fill_str(N2)
    tmp_dict = dict(zip("1 2 3 4 5 6 7 8".split(), (N1 + N2)))
    Y = ""
    for i in range(0, n):
        Y += tmp_dict[P[i]]

    X = int(Y, 2)
    print(str(X))
    handle.write(str(X))
    handle.write('\n')

handle.close()
