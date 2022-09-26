import java.io.*;
import java.util.*;

public class MyClass {
    static class El {
        int i;
        int j;
        int prior;

        El(int i, int j, int prior) {
            this.i = i;
            this.j = j;
            this.prior = prior;
        }
    }

    static int n;
    static int m;
    static int[][] A;
    static int[][] B;
    static int[][] watched;
    static int amountWater;
    static PriorityQueue<El> queue;

    static El tm;
    static int it;
    static int jt;
    static int priort;
    static boolean left, right, up, down;

    static int n_;
    static int m_;


    static void neighbour(int a, int b, int mainLvl) {
        if ((watched[a][b] == 0) && (B[a][b] > mainLvl)) {
            queue.add(new El(a, b, Math.max(mainLvl, A[a][b])));
        }
    }

    public static void main(String[] args) {
        //public void enterInform () throws IOException {
        //Files.lines(Paths.get("in.txt"), StandardCharsets.UTF_8).forEach(System.out::println);
        StringBuilder strB = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader("in.txt"))) {
            while (reader.ready()) {
                strB.append(reader.readLine());
                strB.append(" ");
            }
        } catch (IOException ignored) {
        }
        String[] buf = strB.toString().split(" ");
        n = Integer.parseInt(buf[0]);
        m = Integer.parseInt(buf[1]);
        A = new int[n][m];
        B = new int[n][m];
        watched = new int[n][m];
        n_ = n - 1;
        m_ = m - 1;

        int e = 2;
        for (int i = 0; i < n; i++) {
            for (int j = e; j < e + m; j++) {
                A[i][j - e] = Integer.parseInt(buf[j]);
                B[i][j - e] = 2001;
            }
            e += m;
        }
        // }


        //public void funcQueue () {
        if(n>100){
            queue = new PriorityQueue<>(n/10, Comparator.comparingInt(a -> a.prior));
        }
        if(n>20) {
            queue = new PriorityQueue<>(n/5, Comparator.comparingInt(a -> a.prior));
        }
        else {
            queue = new PriorityQueue<>(n, Comparator.comparingInt(a -> a.prior));
        }
        for (int i = 0; i < n; i++) {
            queue.add(new El(i, 0, A[i][0]));
            queue.add(new El(i, m_, A[i][m_]));
        }
        for (int i = 1; i < m_; i++) {
            queue.add(new El(0, i, A[0][i]));
            queue.add(new El(n_, i, A[n_][i]));
        }
        /*System.out.println();
        while (queue.size() > 0) {
            System.out.println(Objects.requireNonNull(queue.poll()).prior);
        }*/


        while (queue.size() > 0) {
            tm = queue.poll();
            it = tm.i;
            jt = tm.j;
            priort = tm.prior;

            if (watched[it][jt] == 0) {
                up = it == 0;
                down = it == n_;
                left = jt == 0;
                right = jt == m_;

                B[it][jt] = priort;
                watched[it][jt] = 1;

                if (!up) {
                    neighbour(it - 1, jt, priort);
                }
                if (!down) {
                    neighbour(it + 1, jt, priort);
                }
                if (!right) {
                    neighbour(it, jt + 1, priort);
                }
                if (!left) {
                    neighbour(it, jt - 1, priort);
                }
            }
        }
        //}


        //////////////////////////////////////////////////////////////////////////


        // public void outAnswer () throws IOException {
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(B[i][j] + " ");
            }
            System.out.println();
        }*/
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                amountWater += B[i][j] - A[i][j];
            }
        }
        try (PrintWriter pw = new PrintWriter("out.txt")) {
            pw.println(amountWater);
        } catch (IOException ignored) {
        }
        //}
    }
}

/*
public class MyClass implements Runnable {
    public static void main(String[] args) {
        new Thread(null, new MyClass(), "", 64 * 1024 * 1024).start();
    }

    @Override
    public void run() {
        try {
            Number obj = new Number();
            obj.enterInform();
            obj.funcQueue();
            obj.outAnswer();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }
}*/