public class MyMain {
    public static void main(String[] args) {
        try {
            MyArr obj = new MyArr();
            obj.enterSize();
            obj.fillArr();
            obj.printNumEl();
            obj.printArr();
            obj.chooseSort();

            /*int[] arr;
            arr = obj.getArray();
            for (int i = 0; i < arr.length; i++) {
                System.out.println(arr[i]);
            }*/

            obj.start();
            obj.join();

            obj.printArr();
        }
        catch (NumberFormatException | InterruptedException e) {
            System.out.println("You should enter number! ");
        }
    }
}
