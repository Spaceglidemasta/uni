package pckg;

import java.util.ArrayList;



public final class BuilmanLogic {

    

    static final public Building searchBuilding(ArrayList<Building> arr, String name){

        Building out = null;

        for (Building b : arr){
            if(b.getName().equals(name)) out = b;
        }

        return out;

    }

}