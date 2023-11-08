import java.io.*;
import java.net.*;
import java.util.*;
public class Server {
  public static void main(String[] args) {
    DatagramSocket socket = null;
    DatagramPacket outPacket = null;
    byte[] outBuf;
     Scanner in=new Scanner(System.in);  
  System.out.println("\nEnter the port number");
    int PORT = in.nextInt();
System.out.println("\nEnter the port number");
    String group=in.nextLine(); 
    try {
      socket = new DatagramSocket();
      long counter = 0;
      String msg;
	System.out.println("Enter the message");
 	msg=in.nextLine();
       // msg = "This is multicast! " + counter;
        //counter++;
        outBuf = msg.getBytes();
 
        //Send to multicast IP address and port
        InetAddress address = InetAddress.getByName("224.2.2.3");
        outPacket = new DatagramPacket(outBuf, outBuf.length, address, PORT);
 
        socket.send(outPacket);
 
        System.out.println("Server sends : " + msg);
        try {
          Thread.sleep(500);
        } catch (InterruptedException ie) {
        }
      }
    } catch (IOException ioe) {
      System.out.println(ioe);
    }
  }
}
