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

        System.out.println("You create a user via gui...");
        gui.createUser();

        System.out.println("You create a webhook via gui...");
        gui.createWebhook();

        tc.notificationLoop();
        

    }
}