public class MyMain {
    public static void main(String[] args) {
        try {
            CodeWork obj = new CodeWork();
            obj.scanData();
            obj.scanWords();
            obj.findKey();
            //obj.findKey();
            obj.printText();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}