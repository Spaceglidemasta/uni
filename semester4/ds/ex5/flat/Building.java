

import java.util.ArrayList;
import java.util.List;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Building extends UnicastRemoteObject implements BuildingRemote {


    private String name;
    private List<RoomRemote> rooms = new ArrayList<>();


    public Building(String n) throws RemoteException{
        this.name = n;
    }


    /***
     * May return null
     * @param name
     * @return room with the given name
     */
    public RoomRemote searchRoom(String name)throws RemoteException {

        for(RoomRemote room : rooms){
            if (room.getName().equals(name)){
                return room;
            }
        }
        return null;

    }

    public void addRoom(RoomRemote room)throws RemoteException {
        rooms.add(room);
    }

    public void addRoom(String name, int floor, double size) throws RemoteException{

        try {
            rooms.add(new Room(name, floor, size));    
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }

    public List<RoomRemote> getRooms() throws RemoteException {
        return rooms;
    }

    public String getName()throws RemoteException {
        return name;
    }
    
}
