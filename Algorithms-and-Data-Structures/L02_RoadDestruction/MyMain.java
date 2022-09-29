import java.io.*;
//import java.util.Scanner;

class Graf {
    public int n;
    public int m;
    public int q;
    public int array[];
    public int count;
    public String[] roads;
    public String[] earthquakes;


    public void enterInform() throws IOException {
        //File fileIn = new File("input.txt");
        //FileReader fr = new FileReader(fileIn);
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String[] buf = reader.readLine().split(" ");
        //Scanner sc = new Scanner(fileIn);
        n = Integer.parseInt(buf[0]);
        count = n;
        m = Integer.parseInt(buf[1]);
        q = Integer.parseInt(buf[2]);

        roads = new String[m];
        earthquakes = new String[q];
        for (int i = 0; i < m; i++) {
            roads[i] = reader.readLine();
        }
        int pos;
        for (int i = 0; i < q; i++) {
            pos = Integer.parseInt(reader.readLine());
            earthquakes[i] = roads[pos - 1];
            roads[pos - 1] = "";
        }

        array = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            array[i] = -1;
        }


        String[] buf2;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            if (!roads[i].equals("")) {
                buf = roads[i].split(" ");
                isFather(Integer.parseInt(buf[0]), Integer.parseInt(buf[1]));
            }
        }

        for (int i = q - 1; i >= 0; i--) {
            if (count > 1) {
                sb.append(0);
            } else {
                sb.append(1);
            }
            buf = earthquakes[i].split(" ");
            isFather(Integer.parseInt(buf[0]), Integer.parseInt(buf[1]));
        }


        try {
            PrintWriter pw = new PrintWriter("output.txt");
            pw.print(sb.reverse());
            pw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }



    private void isFather(int tmp1,int tmp2){
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