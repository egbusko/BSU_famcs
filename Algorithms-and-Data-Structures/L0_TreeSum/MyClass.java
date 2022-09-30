import java.io.*;
import java.util.*;


public class MyClass {
    public static class MyWork {
        private final String pathIn = "input.txt";
        private final String pathOut = "output.txt";
        HashSet h = new HashSet();
        private List<Long> num;
        private long sum;

        public MyWork() {
            num = new ArrayList<>();
            sum = 0;
        }

        public void enterInform() throws FileNotFoundException {
            //long tmp;
            File fileIn = new File(pathIn);
            Scanner sc = new Scanner(fileIn);
            while (sc.hasNext()) {
                //tmp = sc.nextLong();
                h.add(sc.nextLong());
                //if (!num.contains(tmp)) {
                //    num.add(tmp);
                //    sum += tmp;
                //}
            }
        }

        public void countSum() {
            Iterator<Long> i = h.iterator();
            while (i.hasNext()){
                sum += i.next();
            }
            //for (long i : num) {
            //    sum += i;
            //}
        }

        public void outSum() throws IOException {
            try (PrintWriter pw = new PrintWriter(pathOut)) {
                pw.println(sum);
            }
        }
    }

    public static void main(String[] args) {

        try {
            MyWork obj = new MyWork();
            obj.enterInform();
            obj.countSum();
            obj.outSum();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }
}