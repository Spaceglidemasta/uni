package controlling;
import java.util.ArrayList;

import model.User;
import model.WebsiteHook;
import model.enums.ContentCheck_t;

//Afferent Coupling: 1
//Efferent Coupling: 2
//   -> Instability: 2/3


public class DataController {
    
    @SuppressWarnings("unused")
    private String DBport =  "1234";

    //Diese daten sind eigentlich auf der Datenbank
    private ArrayList<User> users = new ArrayList<>();
    private int newest_uid = 0;

    public int addUser(User user){

        user.set_uid(newest_uid);
        System.out.printf("ID of created User: %d\n", newest_uid);

        this.newest_uid += 1;

        users.add(user);

        return this.newest_uid - 1;
    }
    
    public boolean addWebHook(User user, String url, int interval_s, ContentCheck_t cct){

        int pointcount = 0;

        for(int i = 0, n = url.length() ; i < n ; i++) {
            char c = url.charAt(i);

            if (c == '.') pointcount++;

        }

        if(pointcount != 1) return false;

        user.add_webhook(new WebsiteHook(url, interval_s, cct));

        return true;
    }

    public User getUser(int uid){

        for(User user : users){
            if (user.getId() == uid) return user;
        }

        return null;


    }

    public ArrayList<User> getUsers(){
        return users;
    }
    

}
