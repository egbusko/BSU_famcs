import java.io.*;
import java.util.*;

public class MyDijkstra {
    static class El {
        int num;
        long prior;

        El(int num, long prior) {
            this.num = num;
            this.prior = prior;
        }
    }

    static int n;
    static int m;
    static ArrayList<El>[] nodeList;
    static TreeSet<El> queue;
    static long[] D;
    static int[] H;


    public static void main(String[] args) {
        queue = new TreeSet<>((a, b) -> {
            if (a.prior > b.prior) return 1;
            else if (a.prior < b.prior) return -1;
            else {
                if (a.num > b.num) return 1;
                else return -1;
            }

        });
        //public void enterInform () throws IOException {
        //Files.lines(Paths.get("in.txt"), StandardCharsets.UTF_8).forEach(System.out::println);
        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {
            String[] buf = reader.readLine().split(" ");
            n = Integer.parseInt(buf[0]);
            m = Integer.parseInt(buf[1]);

            H = new int[n + 1];
            D = new long[n + 1];
            nodeList = new ArrayList[n + 1];

            for (int i = 1; i <= n; i++) {
                nodeList[i] = new ArrayList<>();
                D[i] = Long.MAX_VALUE;
            }
            for (int i = 1; i <= m; i++) {
                buf = reader.readLine().split(" ");
                nodeList[Integer.parseInt(buf[0])].add(new El(Integer.parseInt(buf[1]), Integer.parseInt(buf[2])));
                nodeList[Integer.parseInt(buf[1])].add(new El(Integer.parseInt(buf[0]), Integer.parseInt(buf[2])));
            }

        } catch (IOException ignored) {
        }

        dijkstra();

        long t = D[n];
        try (PrintWriter pw = new PrintWriter("output.txt")) {
            if ((n == 1) || (t == Long.MAX_VALUE)) {
                pw.print(0);
            } else {
                pw.print(t);
            }
        } catch (IOException ignored) {
        }
    }

    public static void dijkstra() {
        int j;
        long way;
        D[1] = 0;
        queue.add(new El(1, 0));

        while (!queue.isEmpty()) {
            int i = queue.pollFirst().num;
            if (H[i] == 0) {
                H[i] = 1;

                for (El edge : nodeList[i]) {
                    j = edge.num;
                    way = edge.prior;
                    if (D[i] + way < D[j]) {
                        D[j] = D[i] + way;
                        queue.add(new El(j, D[j]));
                    }
                }
            }
        }
    }
}