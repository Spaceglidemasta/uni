package controlling;

import controlling.DataController;
import model.User;
import model.Website;
import model.enums.ContentCheck_t;
import org.junit.jupiter.api.Test;

import java.time.temporal.TemporalAdjuster;

import static org.junit.jupiter.api.Assertions.*;

public class DataControllerTest {


        @Test
        void userAddingTest() {

            DataController dc = new DataController();
            int testid = 7;
            String testname = "name";
            User newuser = new User(testname, testid);

            int newuid = dc.addUser(newuser);

            User result = dc.getUser(newuid);

            assertNotNull(result);

            System.out.println("User adding Test passed.");
        }

        @Test
        void websiteUpdateTest() {

            Website ws = new Website("private.website");

            // Force a website update of some sort

            assertTrue(ws.detectUpdated());

            System.out.println("Website Update Test passed.");

        }

        @Test
        void correctWebsiteInputTest(){
            String tc1 = "googlecom";
            String tc2 = "google.com";
            String tc3 = "google.com.com";

            DataController dc = new DataController();
            User testu = new User("testname", 0);

            assertFalse(
                    dc.addWebHook(testu, tc1, 0, ContentCheck_t.CONTENT_SIZE)
            );

            assertTrue(
                    dc.addWebHook(testu, tc2, 0, ContentCheck_t.CONTENT_SIZE)
            );

            assertFalse(
                    dc.addWebHook(testu, tc3, 0, ContentCheck_t.CONTENT_SIZE)
            );

        }


        // Add more tests ...
}