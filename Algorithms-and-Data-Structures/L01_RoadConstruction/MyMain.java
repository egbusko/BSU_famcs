import java.io.*;
import java.util.Scanner;

class Graf {
    public int n;
    public int q;
    private int array[];
    public int count;


    public void enterInform() throws IOException {
        //File fileIn = new File("input.txt");
        //Scanner sc = new Scanner(fileIn);
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String[] buf = reader.readLine().split(" ");
        n = Integer.parseInt(buf[0]);
        q = Integer.parseInt(buf[1]);
        array = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            array[i] = -1;
        }
        count = n;
        int a = 0;
        int b = 0;
        int tmp1 = 0;
        int tmp2 = 0;

        try (PrintWriter pw = new PrintWriter("output.txt")) {

            for (int i = 0; i < q; i++) {
                buf = reader.readLine().split(" ");
                a = Integer.parseInt(buf[0]);
                b = Integer.parseInt(buf[1]);
                tmp1 = a;
                tmp2 = b;

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
                pw.println(count);
            }
        }
    }
}


public class MyMain implements Runnable {
    public static void main(String[] args) {
        new Thread(null, new MyMain(), "", 64 * 1024 * 1024).start();
    }

    @Override
    public void run() {
        try {
            Graf obj = new Graf();
            obj.enterInform();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}