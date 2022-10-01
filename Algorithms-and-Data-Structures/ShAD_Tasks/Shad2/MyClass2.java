import java.io.*;

public class MyClass2 {
    static int n;
    static int[] A;

    public static long Sum(int l, int r) {
        long tmp = 0;
        for (int i = l; i <= r; i++) {
            tmp += Math.pow(-1, i - l) * A[i];
        }
        return tmp;
    }

    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {
            String[] buf = reader.readLine().split(" ");
            n = Integer.parseInt(buf[0]);
            A = new int[n];

            buf = reader.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                A[i] = Integer.parseInt(buf[i]);
            }
        } catch (IOException ignored) {
        }
        long res = 0;
        long tmp2;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                tmp2 = Sum(i, j);
                if (tmp2 > res) {
                    res = tmp2;
                }
            }
        }


        try (PrintWriter pw = new PrintWriter("output.txt")) {
            pw.println(res);
        } catch (IOException ignored) {
        }
    }
}