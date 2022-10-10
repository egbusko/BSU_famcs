public class MyClass {
    public static void main(String[] args) {
        try {
            MyMatrix obj = new MyMatrix();
            obj.enterSize();
            obj.fillMatrix();
            obj.printMatrix();
            int maxLine = obj.countMaxLine();
            obj.printLine(maxLine);
        }

        catch (NumberFormatException e) {
            System.out.println("You should enter number! ");
        }
        catch (IllegalArgumentException e){
            System.out.println(e.getMessage());
        }

    }
}
