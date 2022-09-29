import java.io.*;
import java.util.Scanner;

class Number {
    public int n;
    public int[][] matrAdjency;
    public int[] array;

    public void enterInform() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String[] buf = reader.readLine().split(" ");
        n = Integer.parseInt(buf[0]);
        matrAdjency = new int [n][n];
        array = new int[n];

        for (int i = 0; i < n; i++) {
            buf = reader.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                matrAdjency[i][j] = Integer.parseInt(buf[j]);
            }
        }
        for (int i = 0; i < n; i++) {
            array[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               if(matrAdjency[i][j] == 1){
                   array[j] = i + 1;
               }
            }
        }
    }


    //////////////////////////////////////////////////////////////////////////


    public void outAnswer() throws IOException {
        try (PrintWriter pw = new PrintWriter("output.txt")) {
            for (int i = 0; i < n; i++) {
                pw.print(array[i] + " ");
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