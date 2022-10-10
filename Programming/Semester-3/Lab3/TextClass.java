import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;


public class TextClass {
    private List<String> myText;
    private List<String> textLargeLetters;


    public void enterText() {
        myText = new ArrayList<String>();
        textLargeLetters = new ArrayList<String>();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your text: \n");
        String tmp;
        while (!(tmp = sc.nextLine()).isEmpty()) {
            myText.add(tmp);
        }
    }


    public void upgradeWords() {
        StringBuilder sb;

        List<String> myList = new ArrayList<>();
        for (int i = 0; i < myText.size(); i++) {
            StringTokenizer st = new StringTokenizer(myText.get(i), " ,.", true);
            while (st.hasMoreTokens()) {
                myList.add(st.nextToken());
            }

            for (int j = 0; j < myList.size(); j++) {
                if (myList.get(j).charAt(0)>= 'a' && myList.get(j).charAt(0)<= 'z' ) {
                    sb = new StringBuilder(myList.remove(j));
                    sb.setCharAt(0, (char) (sb.charAt(0) - 32));
                    myList.add(j, sb.toString());
                }
            }

            sb = new StringBuilder();
            for (String s : myList){
                sb.append(s);
            }
            myList.clear();
            textLargeLetters.add(sb.toString());
        }
    }


    public void printText() {
        System.out.print("Entered text: \n");
        for (String tmpSt : myText) {
            System.out.println(tmpSt);
        }
        System.out.println();
    }


    public void printChangedText() {
        System.out.print("With large letters: \n");
        textLargeLetters.stream().forEach(item-> System.out.println(item));
        System.out.println();
    }
}
