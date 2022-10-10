import java.util.List;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

public class TxtWork {
    private final String pathIn = "input.txt";
    private final String pathOut1 = "output1.txt";
    private final String pathOut2 = "output2.txt";
    private final String pathOut3 = "output3.txt";

    private List<String> text;
    private List<String> textWithNums;
    private List<String> textWithNumsWitoutReps;
    private List<Integer> numreps;

    private List<String> delimstmp;
    private List<String> delims;


    public TxtWork() {
        text = new ArrayList<>();
        textWithNums = new ArrayList<>();
        textWithNumsWitoutReps = new ArrayList<>();
        delimstmp = new ArrayList<>();
        delims = new ArrayList<>();
        numreps = new ArrayList<>();
    }


    public void enterInform() throws FileNotFoundException {
        File fileIn = new File(pathIn);
            Scanner sc = new Scanner(fileIn).useDelimiter("[\\s\\p{Punct}]+");
            while (sc.hasNext()) {
                text.add(sc.next().toLowerCase());
        }
    }


    public void findNumReps() {
        int numtmp = 0;
        for (String i : text) {
            for (String j : text) {
                if (i.equals(j)) {
                    numtmp++;
                }
            }
            numreps.add(numtmp);
            numtmp = 0;
        }
    }


    public void makeTxtNums() {
        Iterator<String> iterator = text.iterator();
        Iterator<Integer> iterator2 = numreps.iterator();
        while (iterator.hasNext()) {
            textWithNums.add(iterator.next() + "(" + iterator2.next() + ")");
        }
    }


    public void sortText() {
        textWithNums = textWithNums.stream().sorted((a, b) -> b.charAt(b.length() - 2) - a.charAt(a.length() - 2)).collect(Collectors.toList());
    }


    public void clearReps() {
        for (String s : textWithNums) {
            if (!textWithNumsWitoutReps.contains(s)) {
                textWithNumsWitoutReps.add(s);
            }
        }
    }


    public void writeOutput1() throws IOException {
        try (FileWriter filew1 = new FileWriter(pathOut1)) {
            for (String w : textWithNumsWitoutReps) {
                filew1.write(w + " ");
            }

        }
    }


    public void enterDelims() throws FileNotFoundException {
        File fileIn = new File(pathIn);
        Scanner sc = new Scanner(fileIn).useDelimiter("[^\\s\\p{Punct}]*");
        while (sc.hasNext()) {
            delimstmp.add(sc.next());
        }
        for (String s : delimstmp) {
            if (!delims.contains(s)) {
                delims.add(s);
            }
        }

    }


    private void sortDelimsDown() {
        delims = delims.stream().sorted(new Comparator<String>() {
                                            @Override
                                            public int compare(String a, String b) {
                                                return b.compareTo(a);
                                            }
                                        }
        ).collect(Collectors.toList());
    }

    private void sortDelimsUp() {
        delims = delims.stream().sorted(new Comparator<String>() {
                                            @Override
                                            public int compare(String a, String b) {
                                                return a.compareTo(b);
                                            }
                                        }
        ).collect(Collectors.toList());
    }

    public void writeOutput2() throws IOException {
        sortDelimsUp();
        try (FileWriter filew2 = new FileWriter(pathOut2)) {
            for (String w : delims) {
                filew2.write("|" + w + "|" + "\n");
            }

        }
    }


    public void writeOutput3() throws IOException {
        sortDelimsDown();
        try (FileWriter filew3 = new FileWriter(pathOut3)) {
            for (String w : delims) {
                filew3.write("|" + w + "|" + "\n");
            }

        }
    }


    public void outTxt2() {
        for (String w : textWithNums) {
            System.out.println(w + " ");
        }
        System.out.println("\n");
    }

    public void outTxt3() {
        for (String w : textWithNumsWitoutReps) {
            System.out.println(w + " ");
        }
        System.out.println("\n");
    }

    public void outTxtRep() throws IOException {
        try (FileWriter filew2 = new FileWriter(pathOut2)) {
            for (Integer i : numreps) {
                filew2.write(i + " ");
            }
        }
    }

    public void outDelims() {
        int i = 0;
        for (String w : delims) {
            System.out.println(i + "|" + w + "|");
            i++;
        }
        System.out.println("\n");
    }

}

