package ui;
import java.util.Scanner;

import controlling.DataController;
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

        Scanner sc = new Scanner(System.in);

        
        System.out.println("Provide a Name for the new user:");

        dc.addUser(
            new User(sc.nextLine(), 0)
        );
    }

    public void createWebhook(){

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

        dc.addWebHook(
            user,
            new WebsiteHook(
                url,
                interval
            )
        );

    }

}
