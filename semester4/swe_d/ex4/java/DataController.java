import java.util.ArrayList;

public class DataController {
    
    @SuppressWarnings("unused")
    private String DBport =  "1234";


    //Diese daten sind eigentlich auf der Datenbank
    private ArrayList<User> users = new ArrayList<>();
    private int newest_uid = 0;


    public void addUser(User user){

        user.set_uid(newest_uid);
        System.out.printf("New User ID: %d\n", newest_uid);

        this.newest_uid += 1;

        users.add(user);

    }
    
    public void addWebHook(User user, WebsiteHook webhook){
        user.add_webhook(webhook);
    }

    public User getUser(int uid){

        for(User user : users){
            if (user.getId() == uid) return user;
        }

        return null;


    }
    

}
