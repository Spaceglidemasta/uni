package model;
import java.util.ArrayList;

//Afferent Coupling: 1
//Efferent Coupling: 1
//   -> Instability: 1/2

//Concrete Subject
public class User {
    

    private String name;
    private int uid;
    private ArrayList<WebsiteHook> webhooks = new ArrayList<>();
    //public UserPrefencres preferences;

    public User(String name, int uid){
        this.name = name;
        this.uid = uid;
    }

    public String getName(){
        return this.name;
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
