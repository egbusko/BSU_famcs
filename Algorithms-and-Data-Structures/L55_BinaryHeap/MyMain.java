import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

class BinHeap {
    public int n;
    public int masElems[];
    public boolean flag = true;

    public void enterInform() throws FileNotFoundException {
        File fileIn = new File("input.txt");
        Scanner sc = new Scanner(fileIn);
        n = sc.nextInt();


        masElems = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            masElems[i] = sc.nextInt();
        }
    }



    public void Check() {
        if (n % 2 == 0) {
            for (int i = 1; i <= n / 2 - 1; i++) {
                if (masElems[i]>masElems[2*i] || masElems[i]>masElems[2*i + 1]){
                    flag = false;
                }
            }
            if (masElems[n/2] > masElems[n])
                flag = false;
        } else {
            for (int i = 1; i <= n / 2; i++) {
                if (masElems[i]>masElems[2*i] || masElems[i]>masElems[2*i + 1]){
                    flag = false;
                }
            }
        }
    }

    public void outMas() throws IOException {
        try (PrintWriter pw = new PrintWriter("output.txt")) {
            pw.println(n);
            for (int i = 1; i <= n; i++) {
                pw.print(masElems[i] + " ");
            }
        }
    }

    public void outAnswer() throws IOException {
        try (PrintWriter pw = new PrintWriter("output.txt")) {
            if (flag) {
                pw.println("Yes");
            } else pw.println("No");
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
            BinHeap obj = new BinHeap();
            obj.enterInform();
            obj.Check();
            //obj.outMas();
            obj.outAnswer();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }
}