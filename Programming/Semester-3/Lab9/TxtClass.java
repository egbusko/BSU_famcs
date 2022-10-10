import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TxtClass {
    private List<String> strLib;
    private String pathIn = "input.txt";
    private String pathOut = "output.txt";

    TxtClass() {
        strLib = new ArrayList<>();
    }

    public void enterStr() throws FileNotFoundException {
        File fileIn = new File(pathIn);
        Scanner sc = new Scanner(fileIn);
        while (sc.hasNextLine()) {
            strLib.add(sc.nextLine());
        }
    }


    public void replaceHooks() {
        for (int i = 0; i < strLib.get(0).length()/2 ; i++){
            strLib.add(0, strLib.remove(0).replaceAll("(?<a>[(])(?<b>[^()]*)(?<c>[^()]*)(?<d>[)])", ""));  //\([^)]*\)
        }
        System.out.println(strLib.get(0));
    }

    public void replaceNumerals() {
        strLib.add(1, strLib.remove(1).replaceAll("(?<int>[0-9]{2})(?<others>[0-9]+)", "${int}"));
        System.out.println(strLib.get(1));
    }

    public void replaceNulls() {
        strLib.add(2, strLib.remove(2).replaceAll("(?<fNulls>[0]*)(?<int>[0-9]+)(?<fraction>[\\.][0-9]*)(?<lNum>[1-9])(?<lNulls>[0]*)", "$2$3$4"));  //0123,09090
        strLib.add(2, strLib.remove(2).replaceAll("(?<fNulls>[0]*)(?<int>[0-9]+)(?<lNulls>[\\.][0]*)(?<other>[^0-9]|$)", "${int}${other}"));  //0123,000
        strLib.add(2, strLib.remove(2).replaceAll("(?<sp1>[\\s]+)(?<null>[0]*)(?<sp2>[\\s]+)", "$10$3"));
        System.out.println(strLib.get(2));
    }


    public void writeOutput() throws IOException {
        try (FileWriter filew = new FileWriter(pathOut)) {
            for (String w : strLib) {
                filew.write(w + "\n");
            }
        }
    }
}