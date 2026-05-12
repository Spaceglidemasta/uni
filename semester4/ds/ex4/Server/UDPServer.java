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
			if (b.getName().equals(bname)) return b;
		}
		return null;
	}


	public static byte[] evalCommand(String rawStr){

		ArrayList<String> strings =  new ArrayList<>(Arrays.asList(rawStr.split(" ")));

		String command = strings.getFirst();

		switch (command) {
			case "new":

				try {
					buildings.add(new Building(strings.get(1)));
					return "ok".getBytes();

				} catch (IndexOutOfBoundsException e) {
					System.err.printf("Error: Index out of bounds: \n");
					e.printStackTrace();
					return "error".getBytes();
				}

			//Source: https://stackoverflow.com/questions/160970/how-do-i-invoke-a-java-method-when-given-the-method-name-as-a-string
			case "call":

				Building target = searchBuilding(strings.get(1));

				if (target == null) {
					System.err.println("Could not find target.");
					return "error".getBytes();
				} 

				String methodName = strings.get(2);
				try {
					Object result = null;
					if (methodName.equals("searchRoom")) {
						Method method = target.getClass().getMethod(methodName, String.class);
						result = method.invoke(target, strings.get(3));

					} else if (methodName.equals("getRooms") || methodName.equals("getName")) {
						Method method = target.getClass().getMethod(methodName);
						result = method.invoke(target);

					} else if (methodName.equals("addRoom")) {
						Method method = target.getClass().getMethod(methodName, String.class, int.class, double.class);
						result = method.invoke(target, strings.get(3), Integer.parseInt(strings.get(4)), Double.parseDouble(strings.get(5)));
						

					} else {
						System.err.println("Invalid method or args");
						return "error: invalid method or args".getBytes();
					}

					
					if (result == null) {
						return "null".getBytes();
					} else {
						ByteArrayOutputStream baos = new ByteArrayOutputStream();
						ObjectOutputStream oos = new ObjectOutputStream(baos);
						oos.writeObject(result);
						oos.close();
						return baos.toByteArray();

					}
				} catch (Exception e) {
					e.printStackTrace();
					return "error".getBytes();
				}

				
		
			default:
				return "error: unknown command".getBytes();
		}


	}



public static void main( String args[]){

	Building uni = new Building("FRAUAS");
	uni.addRoom(new Room("DS Übung", 2, 40));
	uni.addRoom(new Room("RTS Weronek", 2, 50));

	buildings.add(uni);

	System.out.println("The Server is running");  
	try(DatagramSocket aSocket = new DatagramSocket (9898)){
	
	byte[] buffer = new byte[1000];
	while(true){
		DatagramPacket request = new DatagramPacket (buffer, buffer.length);
		aSocket.receive (request);
		String msgString = new String(request.getData(), 0, request.getLength());
		System.out.println(" New Call: " + msgString);

		byte[] response = evalCommand(msgString);
																		
		DatagramPacket reply = new DatagramPacket (response,
				response.length, request.getAddress(), request.getPort());
		aSocket.send (reply);
	}
	
	}catch (SocketException e){ System.out.println(" Socket: " + e.getMessage());
	}catch (IOException e) {System.out.println(" IO: " + e.getMessage());}
} // main
} //class UDPServer