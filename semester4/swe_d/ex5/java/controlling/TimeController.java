package controlling;

import model.User;


public class TimeController {


    //normally this wouldnt be here
    private DataController dc;
    

    public TimeController(DataController dc){
        this.dc = dc;
    }


    
    public void notificationLoop(){


        while(true){
            
            for(User user : dc.getUsers()){
                
                user.updateObservers();

            }

        }

    }

}
