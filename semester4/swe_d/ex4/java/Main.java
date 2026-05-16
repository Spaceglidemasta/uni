public class Main {

    public static void main(String[] args) {
        
        System.out.println("Start");

        UI gui = new UI(
            new DataController()
        );

        gui.createUser();

        gui.createWebhook();

    }
}