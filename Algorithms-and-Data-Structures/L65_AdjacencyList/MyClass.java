import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

class Number {
    public int n;
    public int m;
    public ArrayList<Integer>[] coll;

    public void enterInform() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String[] buf = reader.readLine().split(" ");
        n = Integer.parseInt(buf[0]);
        m = Integer.parseInt(buf[1]);
        coll = new ArrayList[n];
        for(int i = 0; i < n; i++){
            coll[i] = new ArrayList<>();
        }

        int a,b;
        for (int i = 0; i < m; i++) {
            buf = reader.readLine().split(" ");
            a = Integer.parseInt(buf[0]);
            b = Integer.parseInt(buf[1]);
            coll[a-1].add(b);
            coll[b-1].add(a);
        }
    }


    //////////////////////////////////////////////////////////////////////////


    public void outAnswer() throws IOException {
        try (PrintWriter pw = new PrintWriter("output.txt")) {
            int tmp;
            for (int i = 0; i < n; i++) {
                pw.print(coll[i].size() + " ");

                for (int j = 0; j < coll[i].size(); j++) {
                    pw.print(coll[i].get(j) + " ");
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