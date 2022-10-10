import java.io.FileNotFoundException;
import java.io.IOException;

public class MyMain {
    public static void main(String[] args) {
        try {
            MyHtml obj = new MyHtml();
            obj.enterInform();
            obj.enterInform2();
            obj.findTags();
            obj.sortMyTags();
            obj.writeTags();
            obj.writeWords();
            obj.writeOutput3();
        }
        catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }
}