package ex2;

import java.io.Serializable;

public class Publication implements Display, Serializable{
    
    protected String title;
    protected String language;
    protected double price;

    Publication(String title, String language, double price){
        this.title      = title;
        this.language   = language;
        this.price      = price;
    }

    @Override
    public void print(){
        System.out.printf("%s is available in the language %s for %s$\n",
        this.title, this.language, this.price);
    }


    @Override
    public String to_str(){
        return String.format("%s is available in the language %s for %s$\n",
        this.title, this.language, this.price);
    }
}
