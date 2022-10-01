import java.io.*;

public class MyClass {
    static int n;
    static int[] arrNum;
    static int[] arrMax;
    static int[] currMax;
    static int[] currMin;

    public static int countMax(int i) {
        int maxTmp = arrNum[0];
        int t = 0;
        for (int j = 1; j < i; j++) {
            t = arrNum[j];
            if (t > maxTmp) {
                maxTmp = t;
            }
        }
        return maxTmp;
    }

    public static int countMin(int i, int k) {
        int minTmp = arrNum[i + 1];
        int t = 0;
        for (int j = i + 1; j < k; j++) {
            t = arrNum[j];
            if (t < minTmp) {
                minTmp = t;
            }
        }
        return minTmp;
    }


    public static void countPower(int k) {
        int[] arr1 = new int[k + 1];

        if (currMax[k - 1] > arrNum[k - 1]) {
            currMax[k] = currMax[k - 1];
        } else {
            currMax[k] = arrNum[k - 1];
        }

        currMin[k - 1] = arrNum[k];
        for (int i = k - 2; i > 0; i--) {
            if (currMin[i+1] > arrNum[i+1]){
                currMin[i]=arrNum[i+1];
            }
            else {
                currMin[i]=currMin[i+1];
            }
        }


        for (int i = 0; i < k; i++) {
            arr1[i] = currMax[i] - currMin[i];
        }

        int maxForStep = arr1[0];
        for (int i = 0; i < k; i++) {
            if (arr1[i] > maxForStep) {
                maxForStep = arr1[i];
            }
        }
        arrMax[k] = maxForStep;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String[] buf = reader.readLine().split(" ");
        n = Integer.parseInt(buf[0]);
        arrNum = new int[n];
        arrMax = new int[n];
        currMax = new int[n];
        currMin = new int[n];

        buf = reader.readLine().split(" ");
        arrNum[0] = Integer.parseInt(buf[0]);

        try (PrintWriter pw = new PrintWriter("output.txt")) {
            for (int i = 1; i < n; i++) {
                arrNum[i] = Integer.parseInt(buf[i]);
                countPower(i);
                pw.print(arrMax[i] + " ");
            }
        } catch (IOException ex) {
        }
    }
}

