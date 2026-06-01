package model;
import java.util.ArrayList;

//Afferent Coupling: 1
//Efferent Coupling: 1
//   -> Instability: 1/2

//Concrete Subject
public class User  implements Subject{
    

    private String name;
    private int uid;
    private ArrayList<Observer> webhooks = new ArrayList<>();
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

    @Override
    public void attach(Observer webhook){
        webhooks.add(webhook);
    }

    public int getId(){
        return uid;
    }

    public ArrayList<Observer> getWebHooks() {
        return webhooks;
    }

    @Override
    public void detach(Observer obs) {
        webhooks.remove(obs);
        
    }

    @Override
    public void updateObservers() {
        
        for (Observer obs : webhooks){
            obs.update();
            
        }
    
    }


}
