package data;
import java.util.ArrayList;

//Afferent Coupling: 1
//Efferent Coupling: 1
//   -> Instability: 1/2

public class User {
    

    public String name;
    public int uid;
    public ArrayList<WebsiteHook> webhooks = new ArrayList<>();
    //public UserPrefencres preferences;

    public User(String name, int uid){
        this.name = name;
        this.uid = uid;
    }


    public void set_uid(int new_uid){
        this.uid = new_uid;
    }

    public void add_webhook(WebsiteHook webhook){
        webhooks.add(webhook);
    }

    public int getId(){
        return uid;
    }

    public ArrayList<WebsiteHook> getWebHooks() {
        return webhooks;
    }


}
