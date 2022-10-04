import java.util.Arrays;

public class CheckClass {
    public void Pirson(double[] a_, int L) { //L-кол-во интервалов
        double[] a;
        a = Arrays.copyOf(a_, a_.length);
        Arrays.sort(a);
        int n = a.length;
        int i = 0;
        int count;
        double xi2 = 0;

        for (int l = 1; l <= L; l++) {
            count = 0;
            while ((a[i] < (double) l / L) && (i < n - 1)) {
                i++;
                count++;
            }
            xi2 += Math.pow(count - (double) n / L, 2) / n * L;
        }
        System.out.print("\r\n" + xi2 + " < 30.14");
    }

    public void Kolmogorov(double[] a_) {
        double[] a;
        a = Arrays.copyOf(a_, a_.length);
        Arrays.sort(a);
        int n = a.length;
        double Dn = 0;
        double tmp;

        for (int i = 0; i < n; i++) {
            tmp = Math.abs((double) (i + 1) / n - a[i]);
            if (tmp > Dn) {
                Dn = tmp;
            }
        }
        System.out.print("\r\n" + Math.sqrt(n) * Dn + "<1.36");
    }
}