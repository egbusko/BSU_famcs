import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Words {
    private final String pathIn = "input.txt";
    private final String pathOut1 = "output1.txt";
    private final String pathOut2 = "output2.txt";
    private final String pathOut3 = "output3.txt";

    private List<Pair> list;
    //Set<String> set;

    public Words() {
        list = new ArrayList<>();
        //set = new TreeSet<String>();
    }

    private boolean containsKey(String word) {
        //    for (Pair item: list){
        //        if(item.getKey().equals(word)){
        //            return true;
        //        }
        //    }
        //    return false;
        return list.stream().filter(item -> item.getKey().equals(word)).findFirst().isPresent();
    }

    private int get(String word) {
        //    for (Pair item : list) {
        //        if (item.getKey().equals(word)) {
        //            return item.getValue();
        //        }
        //    }
        //   return 0;
        return list.stream()
                .filter(item -> item.getKey()
                        .equals(word))
                .findFirst()
                .orElse(null).getValue();
    }

    private void put(String word, int value) {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getKey().equals(word)) {
                list.set(i, new Pair(word, value));
                return;
            }
        }
        list.add(new Pair(word, value));
    }


    public void readFile() throws FileNotFoundException {
        try (Scanner sc = new Scanner(new File(pathIn))) {
            sc.useDelimiter("[\\s\\p{Punct}]+");
            while (sc.hasNext()) {
                String word;
                word = sc.next();
                if (containsKey(word)) {
                    put(word, get(word) + 1);
                } else {
                    put(word, 1);
                }
            }
        }
    }


    public void printConsole() {
        Iterator<Pair> it = list.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }


    public void sort() {
        list = list.stream()
                .sorted((a, b) -> b.getValue() - a.getValue())
                .collect(Collectors.toList());
    }

    public void printF1() throws FileNotFoundException {
        //    try (PrintStream ps = new PrintStream(pathOut1)) {
        //      Iterator<Pair> iterator = list.iterator();
        //    while (iterator.hasNext()) {
        //        ps.println(iterator.next());
        //    }
        // }
        try (PrintStream ps = new PrintStream(pathOut1)) {
            list.stream().forEach(ps::println);
        }
    }


    //public void scanDelims() throws FileNotFoundException {
    //    try (Scanner sc = new Scanner(new File(pathIn))) {
    //        sc.useDelimiter("[^\\s\\p{Punct}]*");
    //        while (sc.hasNext()) {
    //            set.add(sc.next());
    //        }
    //    }
    //}

    public void printF2() throws IOException {
        File file = new File(pathIn);
        Set<Character> delims = new TreeSet<Character>();
        try (Scanner sc = new Scanner(file);
             FileWriter filew2 = new FileWriter(pathOut2)) {
            while (sc.hasNextLine()) {
                String tmp = sc.nextLine().replaceAll("[^\\s\\p{Punct}]", "");
                for (int i = 0; i < tmp.length(); i++) {
                    delims.add(tmp.charAt(i));
                }
            }
            //    for (int item : delims) {
            //        filew2.write("|" + (char) item + "|" + "\n");
            //    }
            delims.stream().forEach(item -> {
                try {
                    filew2.write(item);
                } catch (IOException e) {
                }
            });
        }
    }

    //все символы (по 1 разу)
    public void printF3() throws IOException {
        File file = new File(pathIn);
        Set<Character> chars = new TreeSet<Character>
                ((c1, c2) -> c2.charValue() - c1.charValue());
        int tmp;
        try (FileReader fr = new FileReader(file);
             FileWriter filew3 = new FileWriter(pathOut3)) {
            while ((tmp = fr.read()) != -1) {
                chars.add((char) tmp);
            }
            for (char item : chars) {
                filew3.write("|" + item + "|" + "\n");
            }

        }
    }
}
