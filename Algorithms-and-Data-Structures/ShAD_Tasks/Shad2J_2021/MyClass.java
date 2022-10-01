import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.TreeSet;

public class MyClass {
    static int n;

    static boolean[] arrEx;
    static int[] lenStr;

    static ArrayList<String> listStr;
    static ArrayList<Integer> myList;
    static ArrayList<Integer> maxList;

    static TreeSet<String> queue;

    public static int countMax(int i) {

        String o = queue.pollFirst();
        do {
            o = queue.pollFirst();
            if (o.length()!= tmp){
                queue.add(0);

            }
        }while (true);

        int maxTmp = myList.get(0);
        int t = 0;
        for (int j = 0; j < i; j++) {
            t =myList.get(j);
            if (t > maxTmp) {
                maxTmp = t;
            }
        }
        return maxTmp;
    }



    public static void countLen() {
        for (int i = 0; i < listStr.size(); i++) {
            lenStr[i] = listStr.get(i).length();
        }
    }

    public static void main(String[] args) {
        queue = new TreeSet<>(Comparator.comparingInt(String::length));

        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {
            String[] buf = reader.readLine().split(" ");
            n = Integer.parseInt(buf[0]);
            arrEx = new boolean[n];
            lenStr = new int [n];
            for (int i = 0; i < n; i++) {
                String buf2 = reader.readLine();
                queue.add(buf2);
            }


            countMax(0);

            buf = reader.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                myList.add(Integer.parseInt(buf[i]));
                //countPower();
            }
        } catch (IOException ignored) {
        }

        try (PrintWriter pw = new PrintWriter("output.txt")) {

            for(Integer el : maxList) {
                pw.print(el + " ");
            }
        } catch (IOException ignored) {
        }
    }
}

