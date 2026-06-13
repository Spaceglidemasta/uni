package model;

import model.enums.ContentCheck_t;

//Afferent Coupling: 2
//Efferent Coupling: 1
//   -> Instability: 1/3

//Concrete Observer
public class WebsiteHook implements Observer {

    private String url;
    private int interval_s;
    private ContentCheck_t cct;

    //important attributes

    
    public WebsiteHook(String url, int interval_s, ContentCheck_t cct){
        this.url = url;
        this.interval_s = interval_s;
        this.cct = cct;
    }

    @Override
    public boolean update(){

        System.out.printf("Checking \"%s\" based on %s\n", url, cct.name());

        //updating important attributes...

        //checking website based on selection...

        return true;

    }

    public int get_interval_s() {return interval_s;};


}
