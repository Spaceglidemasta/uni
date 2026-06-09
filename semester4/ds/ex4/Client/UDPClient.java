package Client;

import java.net.*;
import java.util.HashSet;

import Server.Objects.Room;

import java.io.*;

public class UDPClient{
	public static void main( String args[]){

	// args[0]: Message
	// args[1]: Server
	try (DatagramSocket aSocket = new DatagramSocket()) {
		
		String port = args[args.length - 1];
		
		//byte [] m = args[0].getBytes();
		//InetAddress aHost = InetAddress.getByName(port);
		//int serverPort = 9898;
		//DatagramPacket request = new DatagramPacket(m, m.length,
		//                                             aHost, serverPort);
		//aSocket.send (request);

		BuildingProxy bproxy = new BuildingProxy("FRAUAS", aSocket, port);

		String rname = bproxy.getName();

		System.out.println(rname);

		Room[] rooms = bproxy.getRooms();

		bproxy.addRoom(new Room("Secret Room", -1, 100));

		for (Room r : rooms){
			System.out.printf("Room %s is %.2fm² big and is on the %d. floor.\n",
				r.getName(), r.getSize_sqm(), r.getFloor()
			);
		}

		//Room room = bproxy.searchRoom("DS Übung");

		//System.out.printf("Returned Size: %d\n",room.getSize_sqm());

		//System.out.println(" Reply: " + new String(reply.getData()));

		} catch (SocketException e){
			System.out.println("Socket: " + e.getMessage());
		}
	}
} 
