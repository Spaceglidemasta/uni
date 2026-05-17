import controlling.DataController;
import controlling.TimeController;
import ui.UI;

public class Main {

    public static void main(String[] args) {
        
        System.out.println("Start");

        //normally this isnt here
        DataController dc = new DataController();
        TimeController tc = new TimeController(dc);

        UI gui = new UI(dc);

        gui.createUser();

        gui.createWebhook();

        tc.notificationLoop();
        

    }
}