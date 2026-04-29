
import java.util.HashSet;

public class Building {


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
    Room searchRoom(String name){

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

    public HashSet<Room> getRooms() {
        return rooms;
    }

    public String getName() {
        return name;
    }
    
}
