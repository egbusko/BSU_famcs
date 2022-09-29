import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class MyMain {
    public static class MyWork {
        public class Parallelepiped {
            public int num_coord;
            int[] coordinates;
            //public List<Integer> coordinates;
            public int numInvestedFromUp;

            public Parallelepiped(int num_coord) {
                this.num_coord = num_coord;
                coordinates = new int[num_coord];
                //coordinates = new ArrayList<>();
                numInvestedFromUp = 1;
            }

        }

        private final String pathIn = "input.txt";
        private final String pathOut = "output.txt";
        Parallelepiped[] list_figures;
        //private List<Parallelepiped> list_figures = new ArrayList<>();
        private int num_coordinates = 0;
        private int num_parallelepipeds = 0;
        private int max_invest = 0;


        /*public boolean checkFile() throws FileNotFoundException {
            File fileIn = new File(pathIn);
            if (fileIn.length() == 0) {
                try (PrintWriter pw = new PrintWriter(pathOut)) {
                    pw.println(0);
                }
                return false;
            }
            return true;
        }*/

        public void enterInform() throws FileNotFoundException {
            File fileIn = new File(pathIn);
            Scanner sc = new Scanner(fileIn);
            num_coordinates = sc.nextInt();
            num_parallelepipeds = sc.nextInt();
            list_figures = new Parallelepiped[num_parallelepipeds];

            if (num_parallelepipeds != 0 && num_coordinates != 0)
                max_invest = 1;

            for (int i = 0; i < num_parallelepipeds; i++) {
                list_figures[i] = new Parallelepiped(num_coordinates);
                for (int j = 0; j < num_coordinates; j++) {
                    list_figures[i].coordinates[j] = sc.nextInt();
                }
            }
        }


        public void sortCoordinates() {
            int tm;
            for (Parallelepiped w : list_figures) {
                for (int i = 0; i < num_coordinates - 1; i++) {
                    for (int j = i + 1; j < num_coordinates; j++) {
                        if (w.coordinates[i] > w.coordinates[j]) {
                            tm = w.coordinates[i];
                            w.coordinates[i] = w.coordinates[j];
                            w.coordinates[j] = tm;
                        }

                    }
                }

            }
            /* for (Parallelepiped w : list_figures) {
                w.coordinates = w.coordinates.stream().sorted(Comparator.comparingInt(a -> a)).collect(Collectors.toList());
            }*/
        }


        /*public void sortCurrentNum(int coordin) {
            Parallelepiped tmp;
            for (int i = 0; i < num_parallelepipeds - 1; i++) {
                int minInd = i;
                for (int j = i + 1; j < num_parallelepipeds; j++) {
                    if (list_figures[minInd].coordinates[coordin] == list_figures[j].coordinates[coordin] && list_figures[minInd].coordinates[coordin - 1] == list_figures[j].coordinates[coordin - 1]) {
                        if (list_figures[minInd].coordinates[coordin + 1] > list_figures[j].coordinates[coordin + 1]) {
                            minInd = j;
                        }
                    }
                }
                tmp = list_figures[i];
                list_figures[i] = list_figures[minInd];
                list_figures[minInd] = tmp;
            }
        }*/




        public boolean Is1_Less_2(Parallelepiped p1, Parallelepiped p2) {
            for (int i = 0; i < num_coordinates; i++) {
                if (p1.coordinates[i] < p2.coordinates[i]) {
                    break;
                }
                if (p1.coordinates[i] > p2.coordinates[i]){
                    return false;
                }
            }
            return true;
        }


        public void sortAllFigures() {
            Parallelepiped tmp;
            for (int i = 0; i < num_parallelepipeds; i++) {
                int minInd = i;
                for (int j = i + 1; j < num_parallelepipeds; j++) {
                    if (!Is1_Less_2(list_figures[minInd],list_figures[j])) {
                        minInd = j;
                    }
                }
                tmp = list_figures[i];
                list_figures[i] = list_figures[minInd];
                list_figures[minInd] = tmp;
            }
            /*for (int i = 0; i < num_parallelepipeds; i++) {
                int minInd = i;
                for (int j = i + 1; j < num_parallelepipeds; j++) {
                    if (list_figures[minInd].coordinates[0] > list_figures[j].coordinates[0]) {
                        minInd = j;
                    }
                }
                tmp = list_figures[i];
                list_figures[i] = list_figures[minInd];
                list_figures[minInd] = tmp;
            }*/
            /*for (int i = 1; i < num_coordinates - 1; i++) {
                sortCurrentNum(i);
            }*/
        }





        public void countAllInvest() {
            for (int i = 0; i < num_parallelepipeds; i++) {
                for (int j = i - 1; j >= 0; j--) {
                    if (IsOneInvIntoOther(list_figures[j], list_figures[i])) {
                        if (list_figures[j].numInvestedFromUp == j + 1) {
                            if (list_figures[j].numInvestedFromUp >= list_figures[i].numInvestedFromUp) {
                                list_figures[i].numInvestedFromUp = list_figures[j].numInvestedFromUp + 1;
                                if (list_figures[i].numInvestedFromUp > max_invest) {
                                    max_invest = list_figures[i].numInvestedFromUp;
                                }
                            }
                            break;
                        }
                        if (list_figures[j].numInvestedFromUp >= list_figures[i].numInvestedFromUp) {
                            list_figures[i].numInvestedFromUp = list_figures[j].numInvestedFromUp + 1;
                            if (list_figures[i].numInvestedFromUp > max_invest) {
                                max_invest = list_figures[i].numInvestedFromUp;
                            }
                        }

                    }
                }
            }
        }


        private boolean IsOneInvIntoOther(Parallelepiped p1, Parallelepiped p2) {
            for (int i = num_coordinates - 1; i >= 0; i--) {
                if (p1.coordinates[i] > p2.coordinates[i]) {
                    return false;
                }
            }
            return true;
        }


        public void outMaxInvest() throws IOException {
            try (PrintWriter pw = new PrintWriter(pathOut)) {
                pw.println(max_invest);
            }
        }


        public void outParals() throws IOException {
            try (PrintWriter pw = new PrintWriter(pathOut)) {
                for (Parallelepiped w : list_figures) {
                    for (int j : w.coordinates) {
                        pw.print(j + " ");
                    }
                    pw.println();
                }
            }
        }
    }


    public static void main(String[] args) {
        try {

            MyWork obj = new MyWork();
            //if (obj.checkFile()) {
            obj.enterInform();

            obj.sortCoordinates();
            obj.sortAllFigures();

            obj.countAllInvest();
            obj.outMaxInvest();
            //obj.outParals();
            //}
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }
}
