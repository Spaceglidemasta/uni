package Client;


import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.HashSet;

import Server.Objects.Room;

public class BuildingProxy {

    private String name;
    private String port;
    private HashSet<Room> rooms = new HashSet<>();
    private DatagramSocket socket;

    

    public BuildingProxy(String name, DatagramSocket socket, String port){
        this.name = name;
        this.socket = socket;
        this.port = port;
    }


    private void send(String msg){

        try {

            byte [] m = msg.getBytes();      
            InetAddress aHost = InetAddress.getByName(port);
            int serverPort = 9898;
            DatagramPacket request = new DatagramPacket (m, m.length,
                                                        aHost, serverPort);
            socket.send (request);
            
        } catch (Exception e) {
            e.printStackTrace();
        }


        
    } 
    


    /***
     * May return null
     * @param name
     * @return room with the given name
     */
    public void searchRoom(String name){

        send(this.name + " search " + name);

    }

    public void addRoom(Room room) {
        send("call " + this.name + " addRoom");
    }

    public void addRoom(String name, int floor, double size){
        send(String.format("call %s addRoom %s %d %f",
            this.name,
            name,
            floor,
            size
        ));
    }

    public void getRooms() {
        send("call " + this.name + " getRooms");
    }

    public void getName() {
        send("call " + this.name + " getName");
    }
    

}
