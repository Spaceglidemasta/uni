package controlling;

import java.util.ArrayList;

import model.User;
import model.WebsiteHook;

public class TimeController {


    //normally this wouldnt be here
    private DataController dc;
    

    public TimeController(DataController dc){
        this.dc = dc;
    }


    
    public void notificationLoop(){


        while(true){

            ArrayList<User> users = dc.getUsers();
            
            for(User user : users){
                
                for(WebsiteHook webhook : user.getWebHooks()){


                    webhook.checkWebsite();

                    try {
                        Thread.sleep(
                            webhook.get_interval_s() * 1000
                        );    
                    } catch (Exception e) {
                        e.printStackTrace();
                    }

                    


                }



            }

        }


    }

}
