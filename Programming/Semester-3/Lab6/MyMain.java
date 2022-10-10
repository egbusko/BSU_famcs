import java.io.FileInputStream;
import java.io.IOException;
import java.util.logging.*;

public class MyMain {
    private static final Logger logger = Logger.getLogger("log");

    public static void main(String[] args) throws IOException {
        LogManager.getLogManager().readConfiguration(new FileInputStream("logging.properties"));
        try {
            DataFinder df = new DataFinder();
            df.fillFileRequest();
        }
        catch (Exception e) {
            logger.info(e.getMessage() + "\n");
        }
    }
}