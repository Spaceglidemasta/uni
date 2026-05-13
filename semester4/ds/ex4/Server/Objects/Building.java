package Server.Objects;
import java.net.DatagramSocket;
import java.util.Arrays;
import java.util.HashSet;
import java.io.Serializable;

public class Building implements Serializable {


    private String name;
    private HashSet<Room> rooms = new HashSet<>();


    public Building(String n){
        this.name = n;
    }


    /***
     * May return null
     * @param name
     * @return room with the given name
     */
    public Room searchRoom(String name){

        for(Room room : rooms){
            if (room.getName().equals(name)){
                return room;
            }
        }
        return null;

    }

    public void addRoom(Room room) {
        rooms.add(room);
    }

    public void addRoom(String name, int floor, double size){
        rooms.add(new Room(name, floor, size));
    }

    public Room[] getRooms() {
        return rooms.toArray(new Room[0]);
    }

    public String getName() {
        return name;
    }
    
}
