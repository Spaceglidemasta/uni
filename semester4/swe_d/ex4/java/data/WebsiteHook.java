package data;

import _notifications.SMS_Notification;

//Afferent Coupling: 2
//Efferent Coupling: 1
//   -> Instability: 1/3

public class WebsiteHook {

    private String url;
    private int interval_s;

    
    public WebsiteHook(String url, int interval_s){
        this.url = url;
        this.interval_s = interval_s;
    }

    public void checkWebsite(){

        System.out.printf("Checking \"%s\"...\n", url);

        SMS_Notification smsnot = new SMS_Notification();

        smsnot.notify_user();

    }

    public int get_interval_s() {return interval_s;};


}
