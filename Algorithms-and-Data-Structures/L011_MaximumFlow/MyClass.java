import java.io.*;
import java.util.*;

public class MyClass {
    static class El {
        int num;
        int prior;

        El(int num, int prior) {
            this.num = num;
            this.prior = prior;
        }
    }

    static int n;
    static int m;
    static int s;
    static int f;
    static int q;
    static ArrayList<El>[] nodeList;
    static TreeSet<El> queue;
    static int[] D;
    static int[] prevs;
    static int[] nodeWeight;


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

            D = new int[n + 1];
            prevs = new int[n + 1];
            nodeWeight = new int[n + 1];
            nodeList = new ArrayList[n + 1];

            for (int i = 1; i <= n; i++) {
                nodeList[i] = new ArrayList<>();
                D[i] = Integer.MAX_VALUE;
            }
            for (int i = 1; i <= m; i++) {
                buf = reader.readLine().split(" ");
                nodeList[Integer.parseInt(buf[0])].add(new El(Integer.parseInt(buf[1]), Integer.parseInt(buf[2])));
                nodeList[Integer.parseInt(buf[1])].add(new El(Integer.parseInt(buf[0]), Integer.parseInt(buf[2])));
            }

            buf = reader.readLine().split(" ");
            s = Integer.parseInt(buf[0]);
            f = Integer.parseInt(buf[1]);
            q = Integer.parseInt(buf[2]);
        } catch (IOException ignored) {
        }
        for (int i = 1; i <= n; i++) {
            nodeWeight[i] = nodeList[i].size();
        }

        dijkstra();

        try (PrintWriter pw = new PrintWriter("output.txt")) {
            int y = prevs[f];
            if (s==f){
                pw.println("Yes");
                pw.print(0);
            }
            else if (y == 0) {
                pw.print("No");
            } else {
                pw.println("Yes");
                pw.print(D[f]);
            }
        } catch (IOException ignored) {
        }
    }

    public static void dijkstra() {
        int j, way;
        D[s] = nodeWeight[s] * q;
        queue.add(new El(s, nodeWeight[s]));

        while (!queue.isEmpty()) {
            int i = queue.pollFirst().num;

            for (El edge : nodeList[i]) {
                j = edge.num;
                way = edge.prior;
                if (D[i] + way + nodeWeight[j] * q < D[j]) {
                    D[j] = D[i] + way + nodeWeight[j] * q;
                    queue.add(new El(j, D[j]));
                    prevs[j] = i;
                }
            }
        }
        D[f] -= nodeWeight[f] * q;
    }
}