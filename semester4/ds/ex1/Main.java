package ex1;
import java.util.ArrayList;


public class Main {

    public static int factorial(int x){

        int result = 1;

        for(;x > 1; x--){
            result *= x;
        }

        return result;
    }


    public static void main(String[] args) {

        ArrayList<Publication> pubs = new ArrayList<>();

        pubs.add(new Book("Hp", "English", 14.99, "ADHBAB", "JKR"));
        pubs.add( new Publication("LotR", "German", 25));

        for (Publication pub : pubs){
            pub.print();
        }

        SuperThread st = new SuperThread();
        st.start();

        SuperThread zwei = new SuperThread();
        zwei.num = 2;
        zwei.start();

    }
}