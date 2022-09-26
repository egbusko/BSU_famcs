import java.io.*;

public class MyClass {
    static int n;
    static int[][] matrAdjency;
    static int[] visited;
    static int tmp = 1;

    public static void main(String[] args) throws IOException {
            BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
            String[] buf = reader.readLine().split(" ");
            n = Integer.parseInt(buf[0]);
            matrAdjency = new int[n][n];
            visited = new int[n];
            for (int i = 0; i < n; i++) {
                buf = reader.readLine().split(" ");
                for (int j = 0; j < buf.length; j++) {
                    matrAdjency[i][j] = Integer.parseInt(buf[j]);
                }
            }

            for (int i = 0; i < n; i++) {
                if (visited[i] == 0) {
                    dfSearch(i);
                }
            }

            PrintWriter pw = new PrintWriter("output.txt");
            for (int i = 0; i < n; i++) {
                pw.print(visited[i] + " ");
            }
            pw.close();
    }

    public static void dfSearch(int i) {
        visited[i] = tmp++;

        for (int j = 0; j < n; j++) {
            if (matrAdjency[i][j] == 1 && visited[j] == 0) {
                dfSearch(j);
            }
        }
    }
}