package ui;
import java.util.Scanner;

import controlling.DataController;
import model.Comparison_t;
import model.User;
import model.WebsiteHook;

//Afferent Coupling: 0
//Efferent Coupling: 3
//   -> Instability: 1

public class UI {
    

    private DataController dc;
    
    public UI(DataController dc){
        this.dc = dc;
    }

    public void createUser(){

        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);

        
        System.out.println("Provide a Name for the new user:");

        dc.addUser(
            new User(sc.nextLine(), 0)
        );
    }

    public void createWebhook(){

        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);

        System.out.println("Provide the UID:");
        int uid = sc.nextInt();
        sc.nextLine();

        User user = dc.getUser(uid);

        if(user == null){
            System.err.printf("User with id %d could not be found inside the DB.\n", uid);
        }

        System.out.println("Provide the URL for the webhook:");
        String url = sc.nextLine();

        System.out.println("Provide the interval for the webhook:");
        int interval = sc.nextInt();

        System.out.println("Provide the comparision type for the webhook:");
        System.out.println("    Content Size (0)");
        System.out.println("    HTML content (1)");
        System.out.println("    Text content (2)");
        int ct = sc.nextInt();

        dc.addWebHook(
            user,
            new WebsiteHook(
                url,
                interval,
                Comparison_t.values()[ct]

            )
        );

    }

}
