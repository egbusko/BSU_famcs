import java.io.*;
import java.util.Scanner;

class Number {
    public int n;
    public int[] array;

    public void enterInform() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String[] buf = reader.readLine().split(" ");
        n = Integer.parseInt(buf[0]);
        array = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            array[i] = 0;
        }

        for (int i = 2; i <= n; i++) {
            buf = reader.readLine().split(" ");
            array[Integer.parseInt(buf[1])] = Integer.parseInt(buf[0]);
        }
    }


    //////////////////////////////////////////////////////////////////////////


    public void outAnswer() throws IOException {
        try (PrintWriter pw = new PrintWriter("output.txt")) {
            for (int i = 1; i <= n; i++) {
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