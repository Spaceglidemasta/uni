
import java.rmi.Naming;


import Proxy.BuildingRemote;
import Proxy.RoomRemote;


public class Main {
  public static void main (String[] args) throws Exception {
    if (args.length != 1)
      throw new IllegalArgumentException ("Syntax: DateClient <hostname>");
          
    try {    
      
      BuildingRemote bprox = (BuildingRemote) Naming.lookup("rmi://" + args[0] + "/gebfrauas");
      RoomRemote[] rooms = bprox.getRooms();

      for (RoomRemote room : rooms){
        System.out.println(room.getName());
      }
        
    } catch (Exception e) {
		System.out.println("DateClient: " + e.getMessage());
	    e.printStackTrace();
	}
    
  }
}
