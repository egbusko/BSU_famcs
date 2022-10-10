import java.util.Random;
import java.util.Scanner;


public class MyMatrix {
    private int lines;
    private int columns;
    private int [][] matrix;


    public void enterSize(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of lines: ");
        lines = Integer.parseInt(sc.next());
        if (lines < 1) {
            throw new IllegalArgumentException("Wrong input of lines");
        }
        System.out.print("Enter number of columns: ");
        columns = Integer.parseInt(sc.next());
        if (columns < 1){
            throw new IllegalArgumentException("Wrong input of columns");
        }
    }


    public void fillMatrix(){
        matrix = new int[lines][columns];
        Random rnd = new Random();
        for (int i = 0; i < matrix.length; i++){
            for (int j = 0; j < matrix[i].length; j++){
                matrix[i][j] = rnd.nextInt(10);
            }
        }
    }


    private boolean checkOdd(int [] mtrxLine){
        for (int i = 0; i < mtrxLine.length; i++){
           if (mtrxLine[i] % 2 == 0){
               return false;
           }
        }
        return true;
    }


    private int sumLine(int [] mtrxLine){
        int sum = 0;
        for (int i = 0; i < mtrxLine.length; i++){
            sum += mtrxLine[i];
        }
        return sum;
    }


    public int countMaxLine(){
        int maxLine = 0;
        int sum1 = 0;
        int sum2 = 0;
        boolean tmp = false;

        for (int i = 0; i < matrix.length; i++){
            tmp = checkOdd(matrix[i]);
            if (tmp){
                sum1 = sumLine(matrix[i]);
                if (sum1 > sum2){
                    maxLine = i;
                }
                sum2= sum1;
                tmp = false;
            }
        }
        if (sum1 != 0){
            return maxLine;
        }
        else {
            throw new IllegalArgumentException("No lines with all odd numbers!");
        }
    }


    public void printMatrix(){
        for (int i = 0; i < matrix.length; i++){
            for (int j = 0; j < matrix[i].length; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }


    public void printLine(int numLine){
        System.out.println("Line is: ");
        for (int i = 0; i < matrix[numLine].length; i++){
            System.out.print(matrix[numLine][i] + " ");
        }
        System.out.println();
    }

}
