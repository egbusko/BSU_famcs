import java.io.*;

public class MyMain {
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String[] buf = reader.readLine().split(" ");
        n = Integer.parseInt(buf[0]);

        buf = reader.readLine().split(" ");

        StringBuilder sb = new StringBuilder();
        StringBuilder present = new StringBuilder();
        for (int j = n - 1; j >= 0; j--) {
            if (present.lastIndexOf(buf[j])==-1) {
                present.append(Integer.parseInt(buf[j]));
            } else {
                sb.append(" " + Integer.parseInt(buf[j]));
            }
        }

        //////////////////////////////////////////////////////////////////////////


        try {
            PrintWriter pw = new PrintWriter("output.txt");
            if (sb.length() == 0) {
                pw.print(0);
            } else {
                pw.println(sb.length()/2);
                pw.print(sb.reverse());
            }
            pw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
