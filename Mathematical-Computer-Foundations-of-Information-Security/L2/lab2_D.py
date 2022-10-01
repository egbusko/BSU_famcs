X = 28
k = 3986
n = 8
handle = open("Result.txt", "w")
print("X = " + str(X) + " = " + str(bin(X)[2:]) + "\n")
handle.write("X = " + str(X) + " = " + str(bin(X)[2:]) + "\n")
print("k = " + str(k) + " = " + str(bin(k)[2:]) + "\n")
handle.write("k = " + str(k) + " = " + str(bin(k)[2:]) + "\n")


def split_str(string):
    half = len(string) // 2
    return str(int(string[:half], 2)), str(int(string[half:], 2))


def fill_str(string):
    while len(string) != 4:
        #tmp = "0" + string
        #string = tmp
        string = "0" + string
    return string


S7 = dict(zip("0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15".split(),
              "1 13 2 9 7 10 6 0 8 12 4 5 15 3 11 14".split()))
S8 = dict(zip("0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15".split(),
              "11 10 15 5 0 12 14 8 6 2 3 9 1 7 13 4".split()))
k = dict(zip("1 2 3 4 5 6 7 8 9 10 11 12".split(), str(bin(k)[2:])))
R1 = "1 4 7 10 2 5 8 11".split()
R2 = "2 5 8 11 3 6 9 12".split()
R3 = "3 6 9 12 10 4 7 1".split()
P = "1 4 7 2 5 8 3 6".split()
k1 = k2 = k3 = ""
for i in range(0, n):
    k1 += k[R1[i]]
    k2 += k[R2[i]]
    k3 += k[R3[i]]
K = [int(k1, 2), int(k2, 2), int(k3, 2)]
for i in range(0, len(K)):
    print("k" + str(i + 1) + " = ", str(bin(K[i])[2:]))

for item in K:
    tmp = str(bin(X + item))[2:]
    offset = len(tmp) % 8
    T1, T2 = split_str(tmp[offset:])
    N1 = str(bin(int(S7[T1])))[2:]
    N2 = str(bin(int(S8[T2])))[2:]
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
