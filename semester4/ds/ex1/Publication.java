package ex1;

public class Publication {
    
    protected String title;
    protected String language;
    protected double price;

    Publication(String title, String language, double price){
        this.title      = title;
        this.language   = language;
        this.price      = price;
    }

    public void print(){
        System.out.printf("%s is available in the language %s for %s$\n",
        this.title, this.language, this.price);
    }

}
