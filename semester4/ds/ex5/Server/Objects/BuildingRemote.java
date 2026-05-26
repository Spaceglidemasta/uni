package Objects;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface BuildingRemote extends Remote{


    public RoomProxy searchRoom(String name) throws RemoteException;

    public void addRoom(RoomProxy room) throws RemoteException;

    public void addRoom(String name, int floor, double size) throws RemoteException;

    public RoomProxy[] getRooms() throws RemoteException;

    public String getName() throws RemoteException;


    
} 