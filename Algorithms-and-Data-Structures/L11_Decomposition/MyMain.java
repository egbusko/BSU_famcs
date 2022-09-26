import java.io.*;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class MyMain {
    static class Divider {
        public int key;
        public Divider next;
        public int numHas;
        public boolean flage;

        public Divider(int key) {
            this.key = key;
            flage = true;
        }
    }

    static int a;
    static int b;
    static int c;
    static Divider masDividers[];
    static int masLength = 0;
    static int numRes = 0;
    static int flagRes = 0;


    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String[] buf = reader.readLine().split(" ");
        a = Integer.parseInt(buf[0]);
        b = Integer.parseInt(buf[1]);
        c = Integer.parseInt(buf[2]);
        if (a < 10000) {
            masDividers = new Divider[a / 2 + 1];
        } else {
            masDividers = new Divider[/*(int) (Math.log(a) / Math.log(2)) + 1*/a / 200];
        }

        int q = a;
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 2; i * i <= q; i++) {
            if (q % i == 0) {
                queue.add(i);
                if (!queue.contains(q / i)) {
                    queue.add(q / i);
                }
            }
        }
        masLength = queue.size() + 2;
        int y = 1;
        masDividers[0] = new Divider(1);
        while (queue.size() > 0) {
            masDividers[y++] = new Divider(queue.poll());
        }
        masDividers[masLength - 1] = new Divider(a);

        //делители числа
        /*for (int j = 1; j <= a / 2; j++) {
            if (a % j == 0) {
                masDividers[masLength++] = new Divider(j);
            }
        }
        masDividers[masLength] = new Divider(a);
        masLength++;*/


        // простые делители
        /*public void divideA () {
            int i = 0;
            while (a % 2 == 0) {
                masDividers[i] = 2;
                a /= 2;
                i++;
            }
            for (int j = 3; j <= a; j = j + 2) {
                while (a % j == 0) {
                    masDividers[i] = j;
                    a /= j;
                    i++;
                }
            }
            masLength = i;
        }*/

        for (int i = 0; i < masLength; i++) {
            for (int j = 0; j < i; j++) {
                if (masDividers[i].key % masDividers[j].key == 0 && masDividers[i].key / masDividers[j].key >= b && masDividers[i].key / masDividers[j].key <= c) {
                    if ((masDividers[i].numHas - 1 > masDividers[j].numHas && masDividers[j].numHas != 0) || masDividers[i].numHas == 0) {
                        if (j == 0) {
                            masDividers[i].next = masDividers[j];
                            masDividers[i].numHas = masDividers[j].numHas + 1;
                        } else if (masDividers[j].numHas != 0) {
                            masDividers[i].next = masDividers[j];
                            masDividers[i].numHas = masDividers[j].numHas + 1;
                        }
                    }
                }
            }
        }


        try (PrintWriter pw = new PrintWriter("output.txt")) {
            /*pw.print(a + " " + b + " " + c);
            pw.println();
            pw.println();

            pw.println(masLength);
            for (int j = 0; j < masLength; j++) {
                pw.print(masDividers[j].key + " ");
            }
            pw.println();
            pw.println();

            Divider tm = masDividers[masLength - 1];
            while (tm != null) {
                numRes++;
                pw.print(tm.key + " ");

                if (tm.key == 1)
                    flagRes = 1;
                tm = tm.next;
            }*/
            //pw.println();
            if (masDividers[masLength - 1].numHas == 0) {
                pw.println(-1);
            } else
                pw.println(masDividers[masLength - 1].numHas);
        }
    }
}
