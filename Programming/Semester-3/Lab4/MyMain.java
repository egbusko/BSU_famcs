import java.io.FileNotFoundException;
import java.io.IOException;

public class MyMain {
    public static void main(String[] args) {
        try {
            MyDelCom obj = new MyDelCom();
            obj.scanData();
            obj.delComments();
            obj.printText();
        }
        catch (FileNotFoundException e) {
            System.out.println("FileNotFoundException");
        } catch (IOException e) {
            System.out.println("IOE");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}