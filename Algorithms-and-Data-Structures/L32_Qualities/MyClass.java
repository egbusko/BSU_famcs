import java.io.*;
import java.util.Scanner;

class Number {
    public int n;
    public int m;
    public String[] qualities;

    public int array[];
    public int count;
    public boolean flag = true;

    public void enterInform() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("equal-not-equal.in"));
        String[] buf = reader.readLine().split(" ");
        n = Integer.parseInt(buf[0]);
        m = Integer.parseInt(buf[1]);
        qualities = new String[m];
        array = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            array[i] = -1;
        }
        count = n;

        for (int i = 0; i < m; i++) {
            qualities[i] = reader.readLine();           //length==8, num==[1],[7], quality==[3]
            //System.out.println(qualities[i]);
        }
    }


    public void allEquals() {
        String[] buf;
        int a = 0;
        int b = 0;
        for (int i = 0; i < m; i++) {
            buf = qualities[i].split(" ");
            if (buf[1].charAt(0) == '=') {
                a = Integer.parseInt(buf[0].substring(1));
                b = Integer.parseInt(buf[2].substring(1));
                //System.out.println(a + " " + b);
                isFather(a, b);
            }
        }
        //for (int i = 1; i < n + 1; i++) {
        //    System.out.print(array[i] + " ");
        //}
    }

    private void isFather(int tmp1, int tmp2) {
        while (array[tmp1] > 0) {
            tmp1 = array[tmp1];
        }
        while (array[tmp2] > 0) {
            tmp2 = array[tmp2];
        }
        if (tmp1 != tmp2) {
            if (array[tmp1] < array[tmp2]) {
                array[tmp1] += array[tmp2];
                array[tmp2] = tmp1;
            } else {
                array[tmp2] += array[tmp1];
                array[tmp1] = tmp2;
            }
            count--;
        }
    }


    public void allNotEquals() {
        //System.out.println();
        String[] buf;
        int a = 0;
        int b = 0;
        for (int i = 0; i < m; i++) {
            buf = qualities[i].split(" ");
            if (buf[1].charAt(0) == '!') {
                a = Integer.parseInt(buf[0].substring(1));
                b = Integer.parseInt(buf[2].substring(1));
                //System.out.println(a + " " + b);
                checkIsFather(a, b);
            }
        }
    }

    private void checkIsFather(int tmp1, int tmp2) {
        while (array[tmp1] > 0) {
            tmp1 = array[tmp1];
        }
        while (array[tmp2] > 0) {
            tmp2 = array[tmp2];
        }
        if (tmp1 == tmp2) {
            flag = false;
        }
    }

    //////////////////////////////////////////////////////////////////////////


    public void outAnswer() throws IOException {
        try (PrintWriter pw = new PrintWriter("equal-not-equal.out")) {
            if (flag) {
                pw.println("Yes");
            } else pw.println("No");
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
            obj.allEquals();
            obj.allNotEquals();
            obj.outAnswer();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }
}