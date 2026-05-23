package model;

//Afferent Coupling: 2
//Efferent Coupling: 1
//   -> Instability: 1/3

//Concrete Observer
public class WebsiteHook implements Observer {

    private String url;
    private int interval_s;

    //important attributes

    
    public WebsiteHook(String url, int interval_s){
        this.url = url;
        this.interval_s = interval_s;
    }

    @Override
    public boolean update(){

        System.out.printf("Checking \"%s\"...\n", url);

        //updating important attributes...

        return true;

    }

    public int get_interval_s() {return interval_s;};


}
