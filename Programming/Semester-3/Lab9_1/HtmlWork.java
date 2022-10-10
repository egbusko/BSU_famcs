import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class HtmlWork {
    private final String pathOut1 = "output1.txt";
    private final String pathOut2 = "output2.txt";
    private List<String> strToWrite1;
    private List<String> strToWrite2;

    public HtmlWork() {
        strToWrite1 = new ArrayList<>();
        strToWrite2 = new ArrayList<>();
    }


    private class RecourseContentType {
        String htmlDocumentType = "text/html";
        String documentType = "text/html";
        String encoding = "UTF-8";

        public RecourseContentType(String contentType) {
            String[] values = contentType.split(";"); // values.length should be 2
            String encoding_result = "";
            int i = 0;
            for (String value : values) {

                value = value.trim();
                if (value.toLowerCase().startsWith("charset=")) {
                    encoding_result = value.substring("charset=".length());
                } else {
                    if (i++ == 0) documentType = value;
                }
            }
            if (!encoding_result.isEmpty()) {
                encoding = encoding_result;
            }
        }

        public boolean isHTML() {
            return htmlDocumentType.equals(documentType) ? true : false;
        }
    }


    public boolean fileCheck(String fileName) throws IOException {
        String strFile;
        strFile = new String(Files.readAllBytes(Paths.get(fileName)));
        strFile = strFile.trim();

        String tmp = "";
        Pattern pattern = Pattern.compile("^[\\s]*https?:\\/\\/(www\\.)?[-a-zA-Z0-9@:%._\\+~#=]{1,256}\\.[a-zA-Z0-9()\\/]{1,6}\\b([-a-zA-Z0-9()@:%_\\+.~#?&\\\\=\\/]*)$");
        Matcher matcher = pattern.matcher(strFile);
        while (matcher.find()) {
            tmp = strFile.substring(matcher.start(), matcher.end());
        }
        if (tmp.isEmpty()) {
            return false;
        }
        return true;
    }


    public void urlWork(String fileName) throws IOException {
        String strUrl;
        strUrl = new String(Files.readAllBytes(Paths.get(fileName)));
        strUrl = strUrl.trim();
        searchTitleOrSize(strUrl);
    }

    public void htmlWork(String fileName) throws IOException {
        String strFile;
        List<String> arrUrl = new ArrayList<>();

        strFile = new String(Files.readAllBytes(Paths.get(fileName)));
        Pattern pattern = Pattern.compile("https?:\\/\\/(www\\.)?[-a-zA-Z0-9@:%._\\+~#=]{1,256}\\.[a-zA-Z0-9()\\/]{1,6}\\b([-a-zA-Z0-9()@:%_\\+.~#?&\\\\=\\/]*)");
        Matcher matcher = pattern.matcher(strFile);
        while (matcher.find()) {
            arrUrl.add(strFile.substring(matcher.start(), matcher.end()));
        }
        for (String w : arrUrl) {
            searchTitleOrSize(w);
        }
    }

    private void searchTitleOrSize(String strInto) throws IOException {
        boolean networkRequestOk = false;
        URL myUrl = new URL(strInto);
        HttpURLConnection myUrlCon = (HttpURLConnection) myUrl.openConnection();
        try {
            if (myUrlCon.getResponseCode() == 200)
                networkRequestOk = true;
        } catch (IOException e) {
        }

        if (networkRequestOk) {
           /* if (myUrlCon.getContentLength() > 0) {
                strToWrite1.put(strInto, myUrlCon.getContentLength() / 1024 + " Mb");
            } */
            StringBuilder result = new StringBuilder();
            RecourseContentType ctype2 = new RecourseContentType(myUrlCon.getContentType());

            if (ctype2.isHTML()) {

                try (InputStreamReader resultStreamReader = new InputStreamReader(myUrl.openStream(), ctype2.encoding);
                     Scanner sc = new Scanner(resultStreamReader);) {
                    while (sc.hasNextLine()) {
                        result.append(sc.nextLine());
                    }
                } catch (IOException e) {
                    result = new StringBuilder();
                }

                if (result.toString().contains("<title>") || result.toString().contains("</title>")) {
                    result = new StringBuilder(result.substring(result.indexOf("<title>") + 7, result.indexOf("</title>")));
                }
                if (result.length() > 0) {
                    strToWrite1.add(strInto + "\t\t\t" + result.toString());
                } else {
                    strToWrite1.add(strInto + "\t\t\tNO TITLE SITE");
                }
                System.out.println(result);
            } else {
                strToWrite1.add(strInto + "\t\t\t" + myUrlCon.getContentLength() / 1024 + " Mb");
            }
        } else {
            strToWrite2.add(strInto);
        }
    }


    public void writeOutput1() throws IOException {
        try (FileWriter filew1 = new FileWriter(pathOut1)) {
            filew1.write("   Site\\file            \t\t\ttitle\\size\n");
            for (String w : strToWrite1) {
                filew1.write(w + "\n");
            }
        }
    }

    public void writeOutput2() throws IOException {
        try (FileWriter filew2 = new FileWriter(pathOut2)) {
            filew2.write("*****NOT FOUND SITES*****\n");
            for (String w : strToWrite2) {
                filew2.write(w + "\n");
            }
        }
    }
}