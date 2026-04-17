package ex1;
import java.util.HashSet;


public class StringReader {
    

        public static void main(String[] args) {
            
            HashSet<String> hs = new HashSet<>();


            for( String arg : args){
                hs.add(arg);
            }

            for (String arg : hs){
                System.out.println(arg);
            }


        }


    


}
