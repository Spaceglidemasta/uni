package model;

import java.util.Random;

//Afferent Coupling: 2
//Efferent Coupling: 1
//   -> Instability: 1/3

//Concrete Observer
public class WebsiteHook implements Observer {

    private String url;
    private int interval_s;
    private Comparison_t comptype;

    //important attributes

    
    public WebsiteHook(String url, int interval_s, Comparison_t comptype){
        this.url = url;
        this.interval_s = interval_s;
        this.comptype = comptype;
    }

    @Override
    public boolean update(){

        System.out.printf("Checking \"%s\" based on %s\n", url, comptype.name());

        Random r = new Random();

        if(r.nextInt() % 5 == 0)
            System.out.printf("Website \"%s\" recieved an update!\n", url);

        try {
            Thread.sleep(interval_s * 1000);
        } catch (Exception e) {
            e.printStackTrace();
        }
        

        return true;

    }

    public int get_interval_s() {return interval_s;};


}
