

import java.rmi.*;

import Objects.Building;
import Objects.BuildingRemote;



public class Main {


  public static void main (String[] args) {

    try {

      BuildingRemote frauas = new Building("FRAUAS");
      

      Naming.rebind("gebfrauas", frauas);
      System.out.println("Frauas object binded."); 
      
      
    } catch (Exception e) {
		  System.out.println("DateServerImpl: " + e.getMessage());
		  e.printStackTrace();
	  }
  }
}
