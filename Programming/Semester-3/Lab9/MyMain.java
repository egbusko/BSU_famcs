import java.io.FileNotFoundException;
import java.io.IOException;

public class MyMain {
    public static void main(String[] args) {
        try {
            TxtClass obj = new TxtClass();
            obj.enterStr();
            obj.replaceHooks();
            obj.replaceNumerals();
            obj.replaceNulls();
            obj.writeOutput();
        }
        catch (FileNotFoundException e) {
            System.out.println("FNF");
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}
//https://regex101.com/r/MYMMFB/3