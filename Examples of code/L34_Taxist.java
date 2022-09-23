import java.io.*;
import java.util.*;

public class MyClass {
    static class El {
        int num;
        int prior;
        boolean direction;

        El(int num, int prior, boolean dir) {
            this.num = num;
            this.prior = prior;
            this.direction = dir;
        }
    }

    static String[] inPut;
    static int n;
    static int m;
    static int k;
    static ArrayList<El>[] nodeList;
    static TreeSet<El> queue;

    static int[] m1;
    static int[] m2;
    static int[] H;
    static int[] H2;


    public static void main(String[] args) {
        queue = new TreeSet<>((a, b) -> {
            if (a.prior > b.prior) return 1;
            else if (a.prior < b.prior) return -1;
            else {
                return Integer.compare(a.num, b.num);
            }
        });
        //public void enterInform () throws IOException {
        //Files.lines(Paths.get("in.txt"), StandardCharsets.UTF_8).forEach(System.out::println);
        String[] buf;
        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {
            buf = reader.readLine().split(" ");
            n = Integer.parseInt(buf[0]);
            m = Integer.parseInt(buf[1]);
            k = Integer.parseInt(buf[2]);
            inPut = new String[m + 1];
            nodeList = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) {
                nodeList[i] = new ArrayList<>();
            }
            for (int i = 1; i <= m; i++) {
                inPut[i] = reader.readLine();
            }
        } catch (IOException ignored) {
        }

        for (int i = 1; i <= m; i++) {
            buf = inPut[i].split(" ");
            nodeList[Integer.parseInt(buf[0])].add(new El(Integer.parseInt(buf[1]), Integer.parseInt(buf[2]), true));
            nodeList[Integer.parseInt(buf[1])].add(new El(Integer.parseInt(buf[0]), Integer.parseInt(buf[2]), false));
        }

        H = new int[n + 1];
        H2 = new int[n + 1];
        m1 = new int[n + 1];
        m2 = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            m1[i] = Integer.MAX_VALUE;
            m2[i] = Integer.MAX_VALUE;
        }

        dijkstra1();
        dijkstra2();

        try (PrintWriter pw = new PrintWriter("output.txt")) {
            int minPath = m1[n];
            int u, v, priort;
            StringBuilder strB = new StringBuilder();
            if (!(minPath == Integer.MAX_VALUE)) {
                for (int i = 1; i <= m; i++) {
                    buf = inPut[i].split(" ");
                    u = Integer.parseInt(buf[0]);
                    v = Integer.parseInt(buf[1]);
                    priort = Integer.parseInt(buf[2]);

                    if (priort + m1[u] + m2[v] <= minPath + k) {
                        if ((m1[u] != Integer.MAX_VALUE) && (m2[v] != Integer.MAX_VALUE)) {
                            strB.append(i).append(" ");
                        }
                    }
                }
                String[] buf2 = strB.toString().split(" ");
                pw.println(buf2.length);
                for (String s : buf2) {
                    pw.println(s);
                }
            } else
                pw.println(0);

        } catch (IOException ignored) {
        }
    }


    public static void dijkstra1() {
        int j, way;
        m1[1] = 0;
        queue.add(new El(1, 0, true));

        while (!queue.isEmpty()) {
            int i = queue.pollFirst().num;

            if (H[i] == 0) {
                H[i] = 1;

                for (El edge : nodeList[i]) {
                    if (edge.direction) {
                        j = edge.num;
                        way = edge.prior;
                        if (m1[i] + way < m1[j]) {
                            m1[j] = m1[i] + way;
                            queue.add(new El(j, m1[j], true));
                        }
                    }
                }
            }
        }
    }


    public static void dijkstra2() {
        int j, way;
        m2[n] = 0;
        queue.add(new El(n, 0, false));

        while (!queue.isEmpty()) {
            int i = queue.pollFirst().num;

            if (H2[i] == 0) {
                H2[i] = 1;

                for (El edge : nodeList[i]) {
                    if (!edge.direction) {
                        j = edge.num;
                        way = edge.prior;
                        if (m2[i] + way < m2[j]) {
                            m2[j] = m2[i] + way;
                            queue.add(new El(j, m2[j], false));
                        }
                    }
                }
            }
        }
    }
}
