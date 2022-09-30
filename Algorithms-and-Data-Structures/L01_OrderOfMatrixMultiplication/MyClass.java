import java.io.*;
import java.util.Scanner;


class SQuare {
    public class Matrix {
        public int numOp = Integer.MAX_VALUE;
        public int n = 0;
        public int m = 0;

        public Matrix(int n, int m) {
            this.n = n;
            this.m = m;
        }
    }

    public int num_mats = 2;
    public Matrix[] matrixs;
    public Matrix[][] squareOfM;

    public int numOperations = 0;


    public void enterInfo() throws IOException {
        File fileIn = new File("input.txt");
        Scanner sc = new Scanner(fileIn);
        num_mats = sc.nextInt();
        matrixs = new Matrix[num_mats];
        squareOfM = new Matrix[num_mats][num_mats];

        for (int i = 0; i < num_mats; i++) {
            matrixs[i] = new Matrix(sc.nextInt(), sc.nextInt());
        }


        for (int i = 0; i < num_mats; i++) {
            for (int j = 0; j < num_mats; j++) {
                squareOfM[i][j] = new Matrix(0, 0);
            }
        }
        for (int i = 0; i < num_mats; i++) {
            squareOfM[i][i].n = matrixs[i].n;
            squareOfM[i][i].m = matrixs[i].m;
            squareOfM[i][i].numOp = 0;
        }
        int rowsLeft = num_mats - 1;
        int a = 0;
        for (int rep = 1; rep < num_mats; rep++) {
            a = rep;
            for (int i = 0; i < rowsLeft; i++) {
                squareOfM[i][i + a].n = squareOfM[i][i + a - 1].n;
                squareOfM[i][i + a].m = matrixs[i + a].m;
            }
            rowsLeft--;
        }
    }




    /*public int multiplyingMatr(Matrix m1, Matrix m2) {
        return m1.n * m2.n * m2.m;
    }*/


    public void runSquare() {
        int rowsLeft = num_mats - 1;
        int a = 0;
        int tmpMulty = 1;
        for (int rep = 1; rep < num_mats; rep++) {
            a = rep;
            //проход по диагонали
            for (int i = 0; i < rowsLeft; i++) {
                int tmpVal;
                //проход для кажд объекта, сравнение
                for (int t = i + a; t > i; t--) {
                    tmpVal = squareOfM[t][i + a].numOp + squareOfM[i][t - 1].numOp + squareOfM[i][t - 1].n* squareOfM[i][t - 1].m * squareOfM[t][i + a].m;
                    if (squareOfM[i][i + a].numOp > tmpVal)
                        squareOfM[i][i + a].numOp = tmpVal;
                }

                /*
                int x = squareOfM[i][i + a - 1].numOp + squareOfM[i][i + a - 1].n * matrixs[i + a].n * matrixs[i + a].m;
                int y = squareOfM[i + 1][i + a].numOp + squareOfM[i + 1][i + a].n * squareOfM[i + 1][i + a].m * matrixs[i].n;

                squareOfM[i][i + a].numOp = Math.min(x, y);*/

               /* if (squareOfM[i][i + a - 1].numOp < squareOfM[i + 1][i + a].numOp) {
                    tmpMulty = squareOfM[i][i + a - 1].n * matrixs[i + a].n * matrixs[i + a].m;
                }
                else if (squareOfM[i][i + a - 1].numOp > squareOfM[i + 1][i + a].numOp) {
                    tmpMulty = squareOfM[i + 1][i + a].n * squareOfM[i + 1][i + a].m * matrixs[i].n;
                }
                else
                    tmpMulty = Math.min(squareOfM[i][i + a - 1].n * matrixs[i + a].n * matrixs[i + a].m,squareOfM[i + 1][i + a].n * squareOfM[i + 1][i + a].m * matrixs[i].n);

                squareOfM[i][i + a].numOp = Math.min(squareOfM[i][i + a - 1].numOp, squareOfM[i + 1][i + a].numOp) + tmpMulty;*/
                tmpMulty = 1;
            }
            rowsLeft--;
        }
    }


    public void outMatr() {
        for (int i = 0; i < num_mats; i++) {
            for (int j = 0; j < num_mats; j++) {
                System.out.print(squareOfM[i][j].n + "," + squareOfM[i][j].m + " " + squareOfM[i][j].numOp + " | ");
            }
            System.out.println();
        }
    }

    public void outNumOper() throws IOException {
        try (PrintWriter pw = new PrintWriter("output.txt")) {
            /*for (Matrix w : matrixs) {
                pw.println(w.n + " " + w.m);
            }*/
            pw.println(squareOfM[0][num_mats - 1].numOp);
        }
    }
}


public class MyClass implements Runnable {
    public static void main(String[] args) {
        new Thread(null, new MyClass(), "", 64 * 1024 * 1024).start();
    }

    @Override
    public void run() {
        try {
            SQuare obj = new SQuare();
            obj.enterInfo();
            obj.runSquare();
            obj.outNumOper();
            obj.outMatr();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }
}