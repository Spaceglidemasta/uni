package Client;


import java.io.ByteArrayInputStream;
import java.io.ObjectInputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.HashSet;

import Server.Objects.Room;

public class BuildingProxy {

    private String name;
    private String port;
    private DatagramSocket socket;

    

    public BuildingProxy(String name, DatagramSocket socket, String port){
        this.name = name;
        this.socket = socket;
        this.port = port;
    }


    private byte[] send(String msg){

        try {

            byte [] m = msg.getBytes();      
            InetAddress aHost = InetAddress.getByName(port);
            int serverPort = 9898;
            DatagramPacket request = new DatagramPacket (m, m.length,
                                                        aHost, serverPort);
            socket.send (request);




            byte[] buffer = new byte[1000];
            DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
            socket.receive (reply);

            return reply.getData();
            
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }

        

        
    }

    private Object bytesToObject(byte[] arr){

        try {
            ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(arr));
            
            return ois.readObject();

        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }

        
    }
    


    /***
     * May return null
     * @param name
     * @return room with the given name
     */
    public Room searchRoom(String name){

        return (Room) bytesToObject(send("call " + this.name + " searchRoom " + name));

    }

    public void addRoom(Room room) {
        send("call " + this.name + " addRoom " + room.getName() + " " + room.getFloor() + " " + room.getSize_sqm());
    }

    public void addRoom(String name, int floor, double size){
        send(String.format("call %s addRoom %s %d %f",
            this.name,
            name,
            floor,
            size
        ));
    }

    public Room[] getRooms() {
        return (Room[]) bytesToObject(send("call " + this.name + " getRooms"));
    }

    public String getName() {
        return (String) bytesToObject(send("call " + this.name + " getName"));
    }
    
    
}
