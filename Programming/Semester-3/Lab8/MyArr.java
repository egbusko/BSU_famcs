import java.util.*;

public class MyArr extends Thread{
    private int num_el;
    private Integer[] array;
    private int typeOfSort;

    public void enterSize() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        num_el = Integer.parseInt(sc.next());
        if (num_el < 1) {
            throw new IllegalArgumentException("Wrong input of lines");
        }
    }

    public void fillArr() {
        array = new Integer[num_el];
        Random rnd = new Random();
        for (int i = 0; i < array.length; i++) {
            array[i] = rnd.nextInt(300);
        }
    }

    public void printNumEl() {
        System.out.print("NumOfEl: " + num_el);
        System.out.println();
    }

    public void printArr() {
        System.out.print("Array: ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    public void chooseSort() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter type of sort: \n1.UP by value\n2.DOWN by value" +
                "\n3.UP by num of digits\n4.DOWN by num of digits\n");
        typeOfSort = Integer.parseInt(sc.next());
    }


    public void switchSort() {
        switch (typeOfSort) {
            case 1:
                sortUpValue();
                break;
            case 2:
                sortDownValue();
                break;
            case 3:
                sortUpDigits();
                break;
            case 4:
                sortDownDigits();
                break;
            default:
                System.out.println("Wrong type of sort");
                break;
        }
    }

    private void sortUpValue() {
        Arrays.sort(array, Comparator.comparingInt(a -> a));
    }

    private void sortDownValue() {
        Arrays.sort(array, (a, b) -> b - a);
    }

    private void sortUpDigits() {
        Arrays.sort(array, Comparator.comparingInt(a -> a.toString().length()));
    }

    private void sortDownDigits() {
        Arrays.sort(array, (a, b) -> b.toString().length() - a.toString().length());
    }

    @Override
    public  void run(){
        switchSort();
    }
}
