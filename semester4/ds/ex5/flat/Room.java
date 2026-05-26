

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Room extends UnicastRemoteObject implements RoomRemote {

    private String name;
    private int floor;
    private double size_sqm;

    public Room(String name, int floor, double size) throws RemoteException{
        this.name = name;
        this.floor = floor;
        this.size_sqm = size;
    }


    public String getName() throws RemoteException{
        return name;
    };

    public int getFloor() throws RemoteException{
        return floor;
    }

    public double getSize_sqm() throws RemoteException{
        return size_sqm;
    }

    public void setSize_sqm(double size_sqm) throws RemoteException{
        System.out.println("Changed size");
        this.size_sqm = size_sqm;
    }
    
}
