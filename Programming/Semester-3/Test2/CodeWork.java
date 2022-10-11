import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class CodeWork {

    private StringBuilder myText;
    private List<String> wordsToFind;

    private String txtIn1 = "input1.txt";
    private String txtIn2 = "input2.txt";
    private String txtOut = "output.txt";
    private boolean hasBr;


    public CodeWork() {
        myText = new StringBuilder();
        wordsToFind = new ArrayList<>();
    }

    public void scanData() throws FileNotFoundException {
        try (Scanner sc = new Scanner(new File(txtIn1))) {
            //sc.useDelimiter("[\\s\\p{Punct}]+");
            while (sc.hasNextLine()) {
                myText.append(sc.nextLine().toLowerCase());
            }
        }
    }

    public void scanWords() throws FileNotFoundException {
        try (Scanner sc = new Scanner(new File(txtIn2))) {
            sc.useDelimiter("[\\s\\p{Punct}]+");
            while (sc.hasNext()) {
                wordsToFind.add(sc.next().toLowerCase());
            }
        }
    }


    public int findKey() {
        boolean flagFind = false;
        int k = -1;
        char[] wordAsArr = new char [myText.length()];


        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < myText.length(); j++) {
                wordAsArr[j] = myText.charAt(j);
                wordAsArr[j] -= 1;
            }

            myText.delete(0,myText.length());
            for (char tmp : wordAsArr) {
                myText.append(tmp);
            }



            for (String w : wordsToFind) {
                if (!(flagFind = tryWords(w))) {
                    flagFind = false;
                }
            }

            if (flagFind) {
                return k;
            }
        }
        return k;


    }



    private boolean tryWords(String w) {
        if (myText.indexOf(w) >= 0) {
            return true;
        } else
            return false;
    }



    public void printText() throws IOException {
        try (FileWriter f = new FileWriter(txtOut)) {
            f.write(myText.toString());
        }
    }
}
