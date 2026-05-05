package Server;


import java.net.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.lang.reflect.Method;

import Server.Objects.Building;
import Server.Objects.Room;

import java.io.*;

public class UDPServer{

	static private ArrayList<Building> buildings = new ArrayList<>();

	public static Building searchBuilding(String bname){
		for(Building b : buildings){
			if (b.getName() == bname) return b;
		}
		return null;
	}


	public static void evalCommand(String rawStr){

		ArrayList<String> strings =  new ArrayList<>(Arrays.asList(rawStr.split(" ")));

		String command = strings.getFirst();

		switch (command) {
			case "new":

				try {
					buildings.add(new Building(strings.get(1)));

				} catch (IndexOutOfBoundsException e) {
					System.err.printf("Error: Index out of bounds: \n");
					e.printStackTrace();
				}

			//Source: https://stackoverflow.com/questions/160970/how-do-i-invoke-a-java-method-when-given-the-method-name-as-a-string
			case "call":

				Building target = searchBuilding(strings.get(1));

				System.out.printf("call got called: %s\n", target.getName());


				try {
					Method method = target.getClass().getMethod(strings.get(2));

					System.out.println(method.invoke(target).toString());

					} catch (Exception e) { e.printStackTrace(); }
					

				break;

				
		
			default:
				break;
		}


	}



public static void main( String args[]){

	Building uni = new Building("FRAUAS");
	uni.addRoom(new Room("DS Übung", 2, 40));

	buildings.add(uni);

	System.out.println("The Server is running");  
	try(DatagramSocket aSocket = new DatagramSocket (9898)){
	
	byte[] buffer = new byte[1000];
	while(true){
		DatagramPacket request = new DatagramPacket (buffer, buffer.length);
		aSocket.receive (request);
		String msgString = new String(request.getData(), 0, request.getLength());
		System.out.println(" New Building: " + msgString);

		Building b = new Building(msgString);

		buildings.add(b);
																		
		DatagramPacket reply = new DatagramPacket (request.getData(),
				request.getLength(), request.getAddress(), request.getPort());
		aSocket.send (reply);
	}
	
	}catch (SocketException e){ System.out.println(" Socket: " + e.getMessage());
	}catch (IOException e) {System.out.println(" IO: " + e.getMessage());}
} // main
} //class UDPServer