import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class MyHtml {

    private final String pathInHtml = "input.html";
    private final String pathInIn = "input.in";
    private final String pathOut1 = "output1.txt";
    private final String pathOut2 = "output2.txt";
    private final String pathOut3 = "output3.txt";
    private List<String> text;
    private List<String> wordstofind;
    private List<String> tags;

    public MyHtml() {
        text = new ArrayList<>();
        wordstofind = new ArrayList<>();
        tags = new ArrayList<>();
    }

    public void enterInform() throws FileNotFoundException {
        File fileIn = new File(pathInHtml);
        Scanner sc = new Scanner(fileIn);
        while (sc.hasNextLine()) {
            text.add(sc.nextLine());
        }
    }

    public void enterInform2() throws FileNotFoundException {
        File fileIn = new File(pathInIn);
        Scanner sc = new Scanner(fileIn);
        sc = new Scanner(fileIn);
        sc.useDelimiter("[\\s;]+");

        while (sc.hasNext()) {
            wordstofind.add(sc.next());
        }
    }

    public void findTags() {
        String tag;
        for (String s : text) {
            Pattern p = Pattern.compile("\\<[^>]*>");
            Matcher m = p.matcher(s);
            while (m.find() && !tags.contains(tag = m.group(0))) {
                tags.add(tag);
            }
        }
    }

    public void sortMyTags() {
        Collections.sort(tags, Comparator.comparingInt(String::length));
    }

    public void writeTags() throws IOException {
        try (FileWriter filew1 = new FileWriter(pathOut1)) {
            for (String s : tags) {
                filew1.write(s + "\n");
            }
        }
    }

    public void writeWords() throws IOException {
        try (FileWriter filew2 = new FileWriter(pathOut2)) {
            String row;
            for (int j = 0; j < text.size(); j++) {
                text.add(j, text.remove(j).replaceAll("\\<[^>]*>", ""));
                row = text.get(j);
                for (int i = 0; i < wordstofind.size(); i++) {
                    if ((row.compareToIgnoreCase(wordstofind.get(i))) == 0) {
                        wordstofind.remove(i);
                        filew2.write(row + " " + text.indexOf(row) + "\n");
                    }
                }
            }
            for (String w : wordstofind) {
                filew2.write(w + " " + -1 + "\n");
            }
        }
    }

    public void writeOutput3() throws IOException {
        try (FileWriter filew3 = new FileWriter(pathOut3)) {
            for (String w : wordstofind) {
                filew3.write(w + "\n");
            }
        }
    }
}