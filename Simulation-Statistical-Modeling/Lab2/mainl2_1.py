import math
import matplotlib.pyplot as plt


class LinearCongruentGenerator:
    parameters = {'x0': 0, 'a': 0, 'c': 0, 'M': 0}
    n = 0
    subsequence_1000 = []
    period = 0

    def __init__(self, n):
        self.n = n

    def read_from_file(self):
        self.subsequence_1000 = []
        self.parameters['x0'] = 174549961
        self.parameters['a'] = 2036045713
        self.parameters['c'] = 111437935
        self.parameters['M'] = 2147483648

    def bsv_generation(self):
        self.subsequence_1000.append(self.parameters['x0'])
        i = 0
        while i != self.n:
            i += 1
            self.subsequence_1000.append(((self.parameters['a'] * self.subsequence_1000[i - 1] + self.parameters['c']) % self.parameters['M']))

        i = 0
        while i != self.n:
            self.subsequence_1000[i] /= self.parameters['M']
            i += 1

        return self.subsequence_1000

    def find_period(self):
        a = self.subsequence_1000[0]
        for i in range(1, int(self.n)):
            if a == self.subsequence_1000[i]:
                self.period = i
                break

    def get_cons(self):
        return self.subsequence_1000

    def get_20(self):
        a = []
        for i in range(0, 20):
            a.append(self.subsequence_1000[i])
        return a

    def get_parameters(self):
        return self.parameters

    def get_period(self):
        return self.period


class BernulliDistribution:
    values = []
    p = 0.25
    q = 1 - p
    unbiased_estimate_expected_value = 0
    unbiased_estimate_dispersion = 0
    expected_value = p
    dispersion = p * q

    unbiased_estimate_excess = 0
    unbiased_estimate_asymmetry = 0
    excess = 1 / (p * q) - 6
    asymmetry = (q - p) / (math.sqrt(p * q))

    def generate(self, subsequence_1000, p):
        for i in range(0, len(subsequence_1000)):
            if subsequence_1000[i] < p:
                self.values.append(1)
            else:
                self.values.append(0)

    def get_20(self):
        for i in range(0, 20):
            a = []
            for i in range(0, 20):
                a.append(self.values[i])
            return a

    def get_unbiased_estimate_expected_value(self):
        return self.unbiased_estimate_expected_value

    def get_unbiased_estimate_dispersion(self):
        return self.unbiased_estimate_dispersion

    def get_expected_value(self):
        return self.expected_value

    def get_dispersion(self):
        return self.dispersion

    def get_unbiased_estimate_excess(self):
        return self.unbiased_estimate_excess

    def get_unbiased_estimate_asymmetry(self):
        return self.unbiased_estimate_asymmetry

    def get_excess(self):
        return self.excess

    def get_asymmetry(self):
        return self.asymmetry

    def find_unbiased_estimate_expected_value(self):
        sum = 0
        for i in range(0, len(self.values)):
            sum += self.values[i]
        self.unbiased_estimate_expected_value = sum / len(self.values)

    def find_unbiased_estimate_dispersion(self):
        sum = 0
        for i in range(0, len(self.values)):
            sum += math.pow(self.values[i] - self.unbiased_estimate_expected_value, 2)
        self.unbiased_estimate_dispersion = sum / len(self.values)

    def empirical_moment(self, number):
        empirical_moment = 0
        for i in range(0, len(self.values)):
            empirical_moment += pow(self.values[i] - self.unbiased_estimate_expected_value, number)
        empirical_moment /= len(self.values)
        return empirical_moment

    def find_unbiased_estimate_asymmetry(self):
        self.unbiased_estimate_asymmetry = self.empirical_moment(3) / pow(math.sqrt(self.unbiased_estimate_dispersion), 3)

    def find_unbiased_estimate_excess(self):
        self.unbiased_estimate_excess = self.empirical_moment(4) / pow(math.sqrt(self.unbiased_estimate_dispersion), 4) - 3

    def draw_bar_graph(self):
        plt.scatter(0, self.q)
        plt.scatter(1, self.p)
        plt.bar([0, 1], height=[1 - self.unbiased_estimate_expected_value, self.unbiased_estimate_expected_value])
        plt.show()

    def draw_empiric(self):
        plt.hist(self.values, histtype='step', cumulative=False, bins=len(self.values))
        plt.show()


class BackBinomialDistribution:
    values = []
    m = 5
    p = 0.25

    unbiased_estimate_expected_value = 0
    unbiased_estimate_dispersion = 0
    unbiased_estimate_excess = 0
    unbiased_estimate_asymmetry = 0

    excess = math.pow(p, 2) / (m * (1 - p)) + 6 / m
    asymmetry = (2 - p) / math.sqrt((m * (1 - p)))
    expected_value = m * (1 - p) / p
    dispersion = m * (1 - p) / math.pow(p, 2)

    def generate(self, subsequence_1000):
        for i in range(0, len(subsequence_1000) - 1):
            q = 1 - self.p
            pm = math.pow(self.p, self.m)
            z = 0
            r = subsequence_1000[i] - pm
            while r > 0:
                z += 1
                pm = pm * q * (self.m - 1 + z) / z
                r -= pm
            self.values.append(z)

    def get_20(self):
        for i in range(0, 20):
            a = []
            for i in range(0, 20):
                a.append(self.values[i])
            return a

    def get_unbiased_estimate_expected_value(self):
        return self.unbiased_estimate_expected_value

    def get_unbiased_estimate_dispersion(self):
        return self.unbiased_estimate_dispersion

    def get_expected_value(self):
        return self.expected_value

    def get_dispersion(self):
        return self.dispersion

    def get_unbiased_estimate_excess(self):
        return self.unbiased_estimate_excess

    def get_unbiased_estimate_asymmetry(self):
        return self.unbiased_estimate_asymmetry

    def get_excess(self):
        return self.excess

    def get_asymmetry(self):
        return self.asymmetry

    def find_unbiased_estimate_expected_value(self):
        sum = 0
        for i in range(0, len(self.values)):
            sum += self.values[i]
        self.unbiased_estimate_expected_value = sum / len(self.values)

    def find_unbiased_estimate_dispersion(self):
        sum = 0
        for i in range(0, len(self.values)):
            sum += math.pow(self.values[i] - self.unbiased_estimate_expected_value, 2)
        self.unbiased_estimate_dispersion = sum / len(self.values)

    def empirical_moment(self, number):
        empirical_moment = 0
        for i in range(0, len(self.values)):
            empirical_moment += pow(self.values[i] - self.unbiased_estimate_expected_value, number)
        empirical_moment /= len(self.values)
        return empirical_moment

    def find_unbiased_estimate_asymmetry(self):
        self.unbiased_estimate_asymmetry = self.empirical_moment(3) / pow(math.sqrt(self.unbiased_estimate_dispersion), 3)

    def find_unbiased_estimate_excess(self):
        self.unbiased_estimate_excess = self.empirical_moment(4) / pow(math.sqrt(self.unbiased_estimate_dispersion), 4) - 3

    def draw_bar_graph(self):
        plt.scatter(0, 1 - self.p)
        plt.scatter(1, self.p)
        plt.bar([0, 1], height=[1 - self.unbiased_estimate_expected_value, self.unbiased_estimate_expected_value])
        plt.show()

    def draw_empiric(self):
        plt.hist(self.values, histtype='step', cumulative=False, bins=len(self.values))
        plt.show()


print("1000 элементов\n")
firstGenerator4 = LinearCongruentGenerator(1000)
firstGenerator4.read_from_file()
firstGenerator4.bsv_generation()
print(firstGenerator4.get_20())

print("\n\nBernulli")
bernulli = BernulliDistribution()
bernulli.generate(firstGenerator4.get_cons(), 0.75)
print(bernulli.get_20())

bernulli.find_unbiased_estimate_expected_value()
print("Несмещенная оценка мат ожидания: " + str(bernulli.get_unbiased_estimate_expected_value()))

bernulli.find_unbiased_estimate_dispersion()
print("Несмещенная оценка дисперсии: " + str(bernulli.get_unbiased_estimate_dispersion()))

print("Математическое ожидание равно: " + str(bernulli.get_expected_value()))
print("Димперсия равна: " + str(bernulli.get_dispersion()))

print("Смещение математического ожидания: " + str(math.fabs(bernulli.get_unbiased_estimate_expected_value() - bernulli.get_expected_value())))
print("Смещение дисперсии: " + str(math.fabs(bernulli.get_unbiased_estimate_dispersion() - bernulli.get_dispersion())))

bernulli.find_unbiased_estimate_asymmetry()
print("Несмещенный коэффициент ассиметрии: " + str(bernulli.get_unbiased_estimate_asymmetry()))
print("Коэффициент ассиметрии: " + str(bernulli.get_asymmetry()))

bernulli.find_unbiased_estimate_excess()
print("Несмещенный коэффициент эксцесса: " + str(bernulli.get_unbiased_estimate_excess()))
print("Коэффициент эксцесса: " + str(bernulli.get_excess()))

# bernulli.draw_bar_graph()
# bernulli.draw_empiric()
#

print("\nBack Binomial")
bbin = BackBinomialDistribution()
bbin.generate(firstGenerator4.get_cons())
print(bbin.get_20())

bbin.find_unbiased_estimate_expected_value()
print("Несмещенная оценка мат ожидания: " + str(bbin.get_unbiased_estimate_expected_value()))

bbin.find_unbiased_estimate_dispersion()
print("Несмещенная оценка дисперсии: " + str(bbin.get_unbiased_estimate_dispersion()))

print("Математическое ожидание равно: " + str(bbin.get_expected_value()))
print("Димперсия равна: " + str(bbin.get_dispersion()))

print("Смещение математического ожидания: " + str(math.fabs(bbin.get_unbiased_estimate_expected_value() - bbin.get_expected_value())))
print("Смещение дисперсии: " + str(math.fabs(bbin.get_unbiased_estimate_dispersion() - bbin.get_dispersion())))

bbin.find_unbiased_estimate_asymmetry()
print("Несмещенный коэффициент ассиметрии: " + str(bbin.get_unbiased_estimate_asymmetry()))
print("Коэффициент ассиметрии: " + str(bbin.get_asymmetry()))

bbin.find_unbiased_estimate_excess()
print("Несмещенный коэффициент эксцесса: " + str(bbin.get_unbiased_estimate_excess()))
print("Коэффициент эксцесса: " + str(bbin.get_excess()))

bbin.draw_bar_graph()
bbin.draw_empiric()

