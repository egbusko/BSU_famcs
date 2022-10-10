import java.io.FileNotFoundException;
import java.io.IOException;

public class MyMain {
    public static void main(String[] args){

        try{
            TxtWork obj = new TxtWork();
            obj.enterInform();
            obj.findNumReps();
            obj.makeTxtNums();
            obj.sortText();
            obj.clearReps();
            obj.writeOutput1();

            obj.enterDelims();
            obj.writeOutput2();
            obj.writeOutput3();
        }

        catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }

}
