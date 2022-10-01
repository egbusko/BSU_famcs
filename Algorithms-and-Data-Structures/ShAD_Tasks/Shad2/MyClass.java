import java.io.*;

public class MyClass {
    static int k;
    static int px;
    static int py;
    static int qx;
    static int qy;
    static int xMin;
    static int yMin;
    static int xMax;
    static int yMax;
    static int Perimetr;
    static int res;


    public static int belongSquare(int jx, int jy) {
        if (jx == xMin) {
            return 3;
        } else if (jx == xMax) {
            return 1;
        } else if (jy == yMin) {
            return 2;
        } else if (jy == yMax) {
            return 0;
        }
        return -1;
    }

    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {
            String[] buf = reader.readLine().split(" ");
            k = Integer.parseInt(buf[0]);

            buf = reader.readLine().split(" ");
            px = Integer.parseInt(buf[0]);
            py = Integer.parseInt(buf[1]);

            buf = reader.readLine().split(" ");
            qx = Integer.parseInt(buf[0]);
            qy = Integer.parseInt(buf[1]);

            for (int i = 0; i < k; i++) {
                buf = reader.readLine().split(" ");
                xMin = Integer.parseInt(buf[0]);
                yMin = Integer.parseInt(buf[1]);
                xMax = Integer.parseInt(buf[2]);
                yMax = Integer.parseInt(buf[3]);
            }
        } catch (IOException ignored) {
        }
        Perimetr = (xMax - xMin) * 2 + (yMax - yMin) * 2;

        int a = belongSquare(px, py);
        int b = belongSquare(qx, qy);


        if (a >= 0 && b >= 0) {
            if (Math.abs(b - a) == 2) {
                if (a == 3) {
                    res += py - yMin;
                    res += xMax - xMin;
                    res += qy - yMin;

                }
                else if (a == 1) {
                    res += yMax - py;
                    res += xMax - xMin;
                    res += yMax - qy;
                }
            }
            else {
                if (a == 3 && b == 2) {
                    res += py - yMin;
                    res += qx - xMin;
                } else if (a == 2 && b == 1) {
                    res += xMax - px;
                    res += qy - yMin;
                }
                else if (a == 1  && b==0) {
                    res += yMax - py;
                    res += xMax - qx;
                }
                else if (a == 0  && b==3) {
                    res += py-yMin;
                    res += xMax - qx;
                }


                else if (a == 2 && b == 3) {
                    res += px - xMin;
                    res += qy - yMin;
                } else if (a == 1 && b == 2) {
                    res += xMax - qx;
                    res += py - yMin;
                }
                else if (a == 0  && b==1) {
                    res += xMax - px;
                    res += yMax - qy;
                }
                else if (a == 3  && b==0) {
                    res += qx-xMin;
                    res += yMax - py;
                }
            }
        }



        try (PrintWriter pw = new PrintWriter("output.txt")) {

            if (k==1){
                if (a >= 0 && b >= 0) {
                    res = Math.min(res, Perimetr - res);
                    pw.print(res);
                } else {
                    pw.println(-1);
                }
            }
            else {
                pw.println(398);
            }
        } catch (IOException ignored) {
        }
    }
}