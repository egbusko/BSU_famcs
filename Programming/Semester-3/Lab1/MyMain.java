public class MyMain {
    public static void main(String[] args) {
        try {
            Function obj = new Function();
            obj.scanData();
            double sum = obj.countFunc();
            obj.printMyResult(sum);
            obj.printMachineResult();
        }

        catch (NumberFormatException e){
            System.out.println(e.getMessage());
        }
    }
}