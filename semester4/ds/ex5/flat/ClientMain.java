
import java.rmi.Naming;




public class ClientMain {
  public static void main (String[] args) throws Exception {
    if (args.length != 1)
      throw new IllegalArgumentException ("Syntax: DateClient <hostname>");
          
    try { 

      System.out.println("Start");
      
      BuildingRemote bprox = (BuildingRemote) Naming.lookup("rmi://" + args[0] + "/gebfrauas");


      System.out.println(bprox.getName());

      bprox.addRoom("ds", 2, 30);
      bprox.addRoom("RA", 2, 40);
      
      RoomRemote dsroom = bprox.searchRoom("ds");
      
      System.out.println(dsroom.getName());
      dsroom.setSize_sqm(10);

      double size = 0;

      for (RoomRemote room : bprox.getRooms()){
        System.out.println(room.getName());
        size += room.getSize_sqm();
      }



      System.err.printf("Total size: %.2fm²\n", size);

        
    } catch (Exception e) {
		System.out.println("DateClient: " + e.getMessage());
	    e.printStackTrace();
	}
    
  }
}
