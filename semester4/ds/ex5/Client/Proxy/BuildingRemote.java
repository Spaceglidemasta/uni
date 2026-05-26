package Proxy;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface BuildingRemote extends Remote{


    public RoomRemote searchRoom(String name) throws RemoteException;

    public void addRoom(RoomRemote room)throws RemoteException;

    public void addRoom(String name, int floor, double size)throws RemoteException;

    public RoomRemote[] getRooms()throws RemoteException;

    public String getName()throws RemoteException;


    
} 