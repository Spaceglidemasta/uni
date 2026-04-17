package ex1;
public class SuperThread extends Thread {
    
    public int num = 0;

    public void run(){

        for( int i = 0; i < 5; i++){

            try {
                sleep(3000);
            } catch (Exception e) {
                e.printStackTrace();
            }

            System.out.println(num);
        }

        
    }


}
