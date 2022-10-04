public class MyMain {
    public static void main(String[] args) {
        Generator gr = new Generator();
        CheckClass ins = new CheckClass();
        int n = 1000;
        int K = 128;

        int a01 = 174549961;
        int c1 = 111437935;
        int a02 = 102312981;
        int c2 = 108500169;

        double[] mkm1;
        double[] mkm2;
        double[] a;

        //15 - 0.417337
        mkm1 = gr.multiCongrMethod(c1, a01, n);
        ins.Pirson(mkm1, 10);
        ins.Kolmogorov(mkm1);

        System.out.println();
        mkm2 = gr.multiCongrMethod(c2, a02, n);
        ins.Pirson(mkm2, 10);
        ins.Kolmogorov(mkm2);

        //1 - 0.042928
        //15 - 0.894963
        System.out.println();
        a = gr.MaklarenMarsali(mkm1, mkm2, K);
        ins.Pirson(a, 10);
        ins.Kolmogorov(a);
    }
}



