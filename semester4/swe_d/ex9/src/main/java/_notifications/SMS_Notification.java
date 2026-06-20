package _notifications;

import model.User;

public class SMS_Notification extends _Notification {
    
    private User user;


    public SMS_Notification(User user){
        this.user = user;
    }


    @Override
    public void notify_user(){
        System.out.printf("Notifiyng %s via SMS... beep beep\n", user.getName());
    }

}
