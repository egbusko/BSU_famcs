import java.io.IOException;
import java.io.File;
import java.util.Scanner;

public class MyMain {
    public static void main(String[] args) throws IOException {
        try {
            DatFinder df = new DatFinder();
            df.createDataBase();
            df.loadToDataBase();

            try (Scanner sc = new Scanner(new File("requests.txt"))) {
                int pos = 0;
                while (sc.hasNextLine()) {
                    df.find(sc.nextLine(), pos);
                    pos++;
                }
            }

            df.dropDataBase();
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
