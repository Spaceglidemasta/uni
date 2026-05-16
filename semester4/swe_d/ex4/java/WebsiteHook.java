public class WebsiteHook {

    private String url;
    private int interval_s;

    
    public WebsiteHook(String url, int interval_s){
        this.url = url;
        this.interval_s = interval_s;
    }

    public void checkWebsite(){

        System.out.printf("Checking \"%s\"...\n", url);

    }

    public int get_interval_s() {return interval_s;};


}
