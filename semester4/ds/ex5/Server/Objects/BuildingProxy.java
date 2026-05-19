package Objects;

import java.rmi.Remote;

public interface BuildingProxy extends Remote{


    public RoomProxy searchRoom(String name);

    public void addRoom(RoomProxy room);

    public void addRoom(String name, int floor, double size);

    public RoomProxy[] getRooms();

    public String getName();


    
} 