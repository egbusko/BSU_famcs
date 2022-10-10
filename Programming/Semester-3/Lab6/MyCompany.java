import org.json.JSONObject;

import java.io.FileWriter;
import java.io.IOException;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class MyCompany {
    private final int NUM_EL = 12;

    private String name;
    private String shortTitle;
    private String dateUpdate;
    private String address;
    private String dateFoundation;
    private String countEmployees;
    private String auditor;
    private String phone;
    private String email;
    private String branch;
    private String activity;
    private String link;

    public MyCompany() {
        name = "";
        shortTitle = "";
        dateUpdate = "";
        address = "";
        dateFoundation = "";
        countEmployees = "";
        auditor = "";
        phone = "";
        email = "";
        branch = "";
        activity = "";
        link = "";
    }

    public MyCompany(String data) {
        String[] dataEl = data.split(";");

        if (dataEl.length < NUM_EL) {
            String[] tmp = new String[NUM_EL];
            for (int i = 0; i < dataEl.length; i++) {
                tmp[i] = dataEl[i];
            }
            for (int i = dataEl.length; i < NUM_EL; i++) {
                tmp[i] = "";
            }
            dataEl = tmp;
        }

        name = dataEl[0];
        shortTitle = dataEl[1];
        dateUpdate = dataEl[2];
        address = dataEl[3];
        dateFoundation = dataEl[4];
        countEmployees = dataEl[5];
        auditor = dataEl[6];
        phone = dataEl[7];
        email = dataEl[8];
        branch = dataEl[9];
        activity = dataEl[10];
        link = dataEl[11];
    }

    public JSONObject compareTitles(String title) {
        if (shortTitle.compareToIgnoreCase(title) == 0) {
            return addToJSON();
        }
        return new JSONObject();
    }

    public JSONObject compareBranches(String branch) {
        if (this.branch.compareToIgnoreCase(branch) == 0) {
            return addToJSON();
        }
        return new JSONObject();
    }

    public JSONObject compareActivities(String activity) {
        if (this.activity.compareToIgnoreCase(activity) == 0) {
            return addToJSON();
        }
        return new JSONObject();
    }

    public JSONObject compareDates(String from, String to) throws ParseException {

        DateFormat formatter = new SimpleDateFormat("dd-mm-yyyy");

        Date dateFr = formatter.parse(from);
        System.out.println(dateFr);
        Date dateTo = formatter.parse(to);
        Date curDate = formatter.parse(dateFoundation);

        if ((curDate.before(dateTo) || curDate.toString().equals(dateTo.toString())) && (curDate.after(dateFr) || curDate.toString().equals(dateFr.toString()))) {
            return addToJSON();
        }
        return new JSONObject();
    }

    public JSONObject compareEmpl(String from, String to) throws NumberFormatException {
        int fr = Integer.parseInt(from);
        int t = Integer.parseInt(to);
        int employees = Integer.parseInt(countEmployees);

        if (fr > t) {
            int tmp = t;
            t = fr;
            fr = tmp;
        }
        if (employees >= fr && employees <= t) {
            return addToJSON();
        }
        return new JSONObject();
    }

    public void writeToXML(FileWriter fw) throws IOException {
        fw.write("<company>\n");
        fw.write("<name>" + name + "</name>\n");
        fw.write("<shortTitle>" + shortTitle + "</shortTitle>\n");
        fw.write("<dateUpdate>" + dateUpdate + "</dateUpdate>\n");
        fw.write("<address>" + address + "</address>\n");
        fw.write("<dateFoundation>" + dateFoundation + "</dateFoundation>\n");
        fw.write("<countEmployees>" + countEmployees + "</countEmployees>\n");
        fw.write("<auditor>" + auditor + "</auditor>\n");
        fw.write("<phone>" + phone + "</phone>\n");
        fw.write("<email>" + email + "</email>\n");
        fw.write("<branch>" + branch + "</branch>\n");
        fw.write("<activity>" + activity + "</activity>\n");
        fw.write("<link>" + link + "</link>\n");
        fw.write("</company>\n\n");
    }

    public JSONObject addToJSON() {
        JSONObject companyAsJS = new JSONObject();
        companyAsJS.put("name", name);
        companyAsJS.put("shortTitle", shortTitle);
        companyAsJS.put("dateUpdate", dateUpdate);
        companyAsJS.put("address", address);
        companyAsJS.put("dateFoundation", dateFoundation);
        companyAsJS.put("countEmployees", countEmployees);
        companyAsJS.put("auditor", auditor);
        companyAsJS.put("phone", phone);
        companyAsJS.put("email", email);
        companyAsJS.put("branch", branch);
        companyAsJS.put("activity", activity);
        companyAsJS.put("link", link);
        return companyAsJS;
    }
}