import java.text.DecimalFormat;
import java.util.Scanner;


class Function{

   private double x;
   private int k;

    public void scanData(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter x=(-1; 1) : ");
        x = Double.parseDouble(sc.next());
        if (x <= -1 || x >= 1){
            throw new NumberFormatException("incorrect x");
        }
        System.out.print("Enter k(limit): ");
        k = Integer.parseInt(sc.next());
        if (k <= 0){
            throw new NumberFormatException("incorrect k");
        }
    }


   public double countFunc(){
        double lim = Math.pow(10, -k);
        double res = 1;
        int numer = 1;
        int denom = 2;
        int degr =  1;
        double tmp = Math.pow(x, degr) / denom;

        while(Math.abs(tmp) >= lim){
            res += tmp;
            numer *= numer + 1;
            denom *= denom + 2;
            tmp = numer * Math.pow(x, ++degr) / denom;
            if(degr % 2 == 0){
                tmp *= -1;
            }
        }
        return res;
    }

    public void printMyResult(double res){
        DecimalFormat df = new DecimalFormat("#.###");
        System.out.println("My calculation: " + df.format(res));
    }

    public void printMachineResult(){
        DecimalFormat df = new DecimalFormat("#.###");
        System.out.println("Machine calculation: " + df.format(Math.sqrt(1+x)));
    }
}
