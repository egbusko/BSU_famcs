import java.io.*;
import java.text.ParseException;
import java.util.*;
import java.util.logging.*;
import org.json.JSONObject;

public class DataFinder {

    private String pathIn = "input.csv";
    private List<MyCompany> data;
    private static final Logger logger = Logger.getLogger("log");

    public DataFinder() throws IOException {
        data = new ArrayList<>();

        File inp = new File(pathIn);
        try (Scanner sc = new Scanner(inp)) {
            while (sc.hasNextLine()) {
                data.add(new MyCompany(sc.nextLine()));
            }
        }
    }

    public void fillFileRequest() throws IOException, ParseException {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter a number of the request: ");
            int req = Integer.parseInt(sc.next());
            int numFound = 0;
            String toFind = null;
            String from = null;
            String to = null;
            String reqText;

            JSONObject jsData = new JSONObject();

            try (FileWriter fwJSON = new FileWriter("output.json")) {
                try (FileWriter fwXML = new FileWriter("output.xml")) {
                    fwXML.write("<output>\n");

                    switch (req) {
                        case 0:
                            return;
                        case 1:
                            reqText = "1.Company by short title";
                            System.out.println(reqText + "\n Enter the title: ");
                            toFind = sc.next();
                            break;
                        case 2:
                            reqText = "2.Company by branch";
                            System.out.println(reqText + "\n Enter the branch: ");
                            toFind = sc.next();
                            break;
                        case 3:
                            reqText = "3.Company by activity";
                            System.out.println(reqText + "\n Enter the activity: ");
                            toFind = sc.next();
                            break;
                        case 4:
                            reqText = "4.Company by foundation date";
                            System.out.println(reqText + "\n Enter the period(from/to): ");
                            from = sc.next();
                            to = sc.next();
                            break;
                        case 5:
                            reqText = "5.Company by employees number";
                            System.out.println(reqText + "\n Enter the period(from/to): ");
                            from = sc.next();
                            to = sc.next();
                            break;
                        default:
                            reqText = "Incorrect request";
                            break;
                    }

                    JSONObject toPut;

                    for (MyCompany elem : data) {
                        switch (req) {
                            case 1:
                                toPut = elem.compareTitles(toFind);
                                break;
                            case 2:
                                toPut = elem.compareBranches(toFind);
                                break;
                            case 3:
                                toPut = elem.compareActivities(toFind);
                                break;
                            case 4:
                                toPut = elem.compareDates(from, to);
                                break;
                            case 5:
                                toPut = elem.compareEmpl(from, to);
                                break;
                            default:
                                throw new IllegalStateException("Unexpected value: " + req);
                        }
                        if (!toPut.isEmpty()) {
                            jsData.put("company_" + numFound, toPut);
                            elem.writeToXML(fwXML);
                            numFound++;
                        }
                    }
                    fwJSON.write(jsData.toString());

                    if (toFind != null) {
                        logger.info("Request: " + reqText + " : " + toFind + " Number of found: " + numFound + "\n");
                    } else if (from != null && to != null) {
                        logger.info("Request: " + reqText + " : " + from + " / " + to + " Number of found: " + numFound + "\n");
                    } else {
                        logger.info(reqText);
                    }
                    fwXML.write("</output>");
                }
            }
        }
    }
}