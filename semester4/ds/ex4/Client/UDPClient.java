package Client;

import java.net.*;
import java.io.*;

public class UDPClient{
  public static void main( String args[]){


    

  // args[0]: Message
  // args[1]: Server
    try {
    
      String port = args[args.length - 1];

      System.out.println(" Message:  " + args.toString());
    
      DatagramSocket aSocket = new DatagramSocket();
      byte [] m = args[0].getBytes();      
      InetAddress aHost = InetAddress.getByName(port);
      int serverPort = 9898;
      DatagramPacket request = new DatagramPacket (m, m.length,
                                                   aHost, serverPort);
      aSocket.send (request);


      BuildingProxy bproxy = new BuildingProxy("FRAUAS", aSocket, port);

      bproxy.getRooms();

      byte[] buffer = new byte[1000];
      DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
      aSocket.receive (reply);
      System.out.println(" Reply: " + new String(reply.getData()));
      aSocket.close();
    }catch (SocketException e){ System.out.println(" Socket: " + e.getMessage());
    }catch (IOException e){ System.out.println(" IO: " + e.getMessage());}
  }
} 
