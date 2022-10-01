import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class MyClass {
    static class El {
        int n;
        int [] massivM;
        int res;

        El(int n) {
            this.n = n;
            massivM = new int[n + 1];
        }
    }

    static int t;
    static El[] mlist;


    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {
            String[] buf = reader.readLine().split(" ");
            t = Integer.parseInt(buf[0]);
            mlist = new El[t];

            int n = 0;
            for (int i = 0; i < t; i++) {
                buf = reader.readLine().split(" ");
                n = Integer.parseInt(buf[0]);
                mlist[i] = new El(n);
                buf = reader.readLine().split(" ");
                for (int j= 0; j < n; j++) {
                    mlist[i].massivM[j] = Integer.parseInt(buf[j]);
                }
            }


            int sum = 0;
            int res = 0;
            double a = 0;
            for (int i = 0; i < t; i++) {
                sum = 0;
                for (int j = 0; j < mlist[i].n; j++){
                    sum += mlist[i].massivM[j];
                }
                res = sum / mlist[i].n;
                mlist[i].res = res;

            }
        } catch (IOException ignored) {
        }

        try (PrintWriter pw = new PrintWriter("output.txt")) {
            for (int i = 0; i < t; i++) {
                for (int j = 0; j < mlist[i].n; j++){
                    pw.print(mlist[i].res + " ");
                }
                if (i != t - 1) {
                    pw.print("\n");
                }

            }

        } catch (IOException ignored) {
        }
    }
}
