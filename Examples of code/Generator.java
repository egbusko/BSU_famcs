import java.util.Arrays;

public class Generator {
    private long M = (long) Math.pow(2, 31);
    private double beta;
    private double alpha[];

    private void calcBeta(int coef_c) {
        beta = (int) Math.max(coef_c, M - coef_c);
    }

    public double[] multiCongrMethod(int coef_c, int coef_a, int n) {
        System.out.println("Multiplicative congruential method:");
        double a[] = new double[n];
        alpha = new double[n + 1];

        calcBeta(coef_c);
        alpha[0] = coef_a;

        for (int i = 1; i < n + 1; i++) {
            alpha[i] = (beta * alpha[i - 1]) % M;
            a[i - 1] = alpha[i] / M;
            System.out.print(a[i - 1] + ", ");
        }
        return a;
    }


    public double[] MaklarenMarsali(double[] b, double[] c, int K) {
        System.out.println("McLaren - Marsalia");
        int n = b.length;
        double a[] = new double[n];
        double[] V;
        int s;
        V = Arrays.copyOf(b, K);

        for (int i = 0; i < n; i++) {
            s = (int) (c[i] * K);
//            System.out.print(s + ": ");
            a[i] = V[s];
            if (i + K < n) {
                V[s] = b[i + K];
            }
            System.out.print(a[i] + ", ");
        }
        return a;
    }
}
