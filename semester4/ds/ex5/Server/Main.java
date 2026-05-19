

import java.rmi.*;

import Objects.Building;


public class Main {
  public Main () throws RemoteException {
  }

  public static void main (String[] args) {

    try {

      Building frauas = new Building("FRAUAS");
      frauas.addRoom("Ds Übung", 2, 40);
      frauas.addRoom("Ra Tawdross", 2, 50);

      Naming.rebind("frauas", frauas);
      System.out.println("Frauas object binded.");
      
      
    } catch (Exception e) {
		System.out.println("DateServerImpl: " + e.getMessage());
		e.printStackTrace();
	}
  }
}
