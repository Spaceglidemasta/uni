package ex2;

import java.io.Serializable;

public class Car implements Display, Serializable {

    private String colour;
    private int ps;
    private double weight;

    public Car(String colour, int ps, double weight){
        this.colour = colour;
        this.ps = ps;
        this.weight = weight;
    }

    @Override
    public void print(){
        System.out.printf("The %s car has %d ps and weighs %f kg.\n",
        colour, ps, weight);
    }

    @Override
    public String to_str(){
        return String.format("The %s car has %d ps and weighs %f kg.\n",
        colour, ps, weight);
    }
    
}
