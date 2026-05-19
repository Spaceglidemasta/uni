
import java.rmi.Naming;


import Proxy.BuildingProxy;
import Proxy.RoomProxy;


public class Main {
  public static void main (String[] args) throws Exception {
    if (args.length != 1)
      throw new IllegalArgumentException ("Syntax: DateClient <hostname>");
          
    try {    
      
      BuildingProxy bprox = (BuildingProxy) Naming.lookup("rmi://" + args[0] + "/frauas");
      RoomProxy[] rooms = bprox.getRooms();

      for (RoomProxy room : rooms){
        System.out.println(room.getName());
      }
        
    } catch (Exception e) {
		System.out.println("DateClient: " + e.getMessage());
	    e.printStackTrace();
	}
    
  }
}
