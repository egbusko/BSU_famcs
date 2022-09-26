import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


class BinomHeap {
    public long n;
    public String masBinN[];
    public String binPresentN = "";


    public void enterInform() throws FileNotFoundException {
        File fileIn = new File("input.txt");
        Scanner sc = new Scanner(fileIn);
        n = sc.nextLong();
        System.out.println(n);
    }


    private void printBinaryform(long number) {
        long remainder;
        if (number <= 1) {
            binPresentN += number;
            return;
        }
        remainder = number % 2;
        printBinaryform(number >> 1);
        binPresentN += remainder;
    }

    public void findHeights() {
        printBinaryform(n);
        masBinN = binPresentN.split("");
        System.out.println(masBinN.length);
    }

    public void outMas() throws IOException {
        try (PrintWriter pw = new PrintWriter("output.txt")) {
            for (int i = masBinN.length - 1; i >= 0; i--) {
                if (masBinN[i].equals("1")) {
                    pw.println(masBinN.length - 1 - i);
                }
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
            BinomHeap obj = new BinomHeap();
            obj.enterInform();
            obj.findHeights();
            obj.outMas();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }
}