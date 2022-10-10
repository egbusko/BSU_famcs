public class MyMain {
    public static void main(String[] args) {
        final String pathIn = "input2.html";
        try {
            boolean tmp;
            HtmlWork obj = new HtmlWork();
            tmp = obj.fileCheck(pathIn);
            System.out.println(tmp);
            if (tmp) {
                obj.urlWork(pathIn);
            } else {
                obj.htmlWork(pathIn);
            }
            obj.writeOutput1();
            obj.writeOutput2();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}