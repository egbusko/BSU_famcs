import java.io.FileNotFoundException;
import java.io.IOException;

public class Main {
    public static void main(String[] args){
        try{
            Words obj = new Words();
            obj.readFile();
            obj.sort();
            obj.printF1();
            //obj.scanDelims();
            obj.printF2();
            obj.printF3();
        }
        catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }

}

