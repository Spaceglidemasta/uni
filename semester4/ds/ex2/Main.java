package ex2;


import java.io.FileInputStream;
import java.io.FileOutputStream;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class Main {


    public static boolean fwrite_array(ArrayList<Display> arr){

        String filename = "data.ser";

        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(filename))) {

            out.writeObject(arr);

            System.out.printf("Successfully wrote to %s\n", filename);

        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }

        return true;
    }


    public static ArrayList<Display> fread_array(){

        String filename = "data.ser";

        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(filename))) {

            return (ArrayList<Display>) in.readObject();

        } catch (Exception e) {
            e.printStackTrace();
    }

    return null;
    }
    
    public static void main(String[] args) {
        ArrayList<Display> arr = new ArrayList<>();

        arr.add(new Car("Red", 300, 2800));
        arr.add(new Publication("Harry Potter", "English", 14.99));
        
        fwrite_array(arr);

        ArrayList<Display> newarr  = fread_array();

        assert (newarr != null);

        for(Display articel : newarr){
            articel.print();
        }

    }
}
