package Objects;

import java.util.HashSet;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Building extends UnicastRemoteObject implements BuildingProxy {


    private String name;
    private HashSet<RoomProxy> rooms = new HashSet<>();


    public Building(String n) throws RemoteException{
        this.name = n;
    }


    /***
     * May return null
     * @param name
     * @return room with the given name
     */
    public RoomProxy searchRoom(String name) {

        for(RoomProxy room : rooms){
            if (room.getName().equals(name)){
                return room;
            }
        }
        return null;

    }

    public void addRoom(RoomProxy room) {
        rooms.add(room);
    }

    public void addRoom(String name, int floor, double size) {

        try {
            rooms.add(new Room(name, floor, size));    
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }

    public RoomProxy[] getRooms() {
        return rooms.toArray(new Room[0]);
    }

    public String getName() {
        return name;
    }
    
}
