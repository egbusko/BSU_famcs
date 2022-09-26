import java.io.*;
import java.util.Scanner;

class Number {
    public int n;
    public int m;
    public int[][] matrAdjency;

    public void enterInform() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String[] buf = reader.readLine().split(" ");
        n = Integer.parseInt(buf[0]);
        m = Integer.parseInt(buf[1]);
        matrAdjency = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrAdjency[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            buf = reader.readLine().split(" ");
            matrAdjency[Integer.parseInt(buf[0])-1][Integer.parseInt(buf[1])-1]=1;
            matrAdjency[Integer.parseInt(buf[1])-1][Integer.parseInt(buf[0])-1]=1;
        }
    }


    //////////////////////////////////////////////////////////////////////////


    public void outAnswer() throws IOException {
        try (PrintWriter pw = new PrintWriter("output.txt")) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    pw.print(matrAdjency[i][j] + " ");
                }
                pw.println();
            }
        }
    }
}


public class MyClass implements Runnable {
    public static void main(String[] args) {
        new Thread(null, new MyClass(), "", 64 * 1024 * 1024).start();
    }

    @Override
    public void run() {
        try {
            Number obj = new Number();
            obj.enterInform();
            obj.outAnswer();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }
}