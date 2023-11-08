import java.io.*;
import java.util.*;
import java.net.*;
public class Client {
  public static void main(String[] args) {
    MulticastSocket socket = null;
    DatagramPacket inPacket = null;
    byte[] inBuf = new byte[256];
    try {
	Scanner in=new Scanner(System.in);
      //Prepare to join multicast group
     int port=in.nextLine();
      socket = new MulticastSocket(pn);
      InetAddress address = InetAddress.getByName("224.2.2.3");
      socket.joinGroup(address);
 
      while (true) {
        inPacket = new DatagramPacket(inBuf, inBuf.length);
        socket.receive(inPacket);
        String msg = new String(inBuf, 0, inPacket.getLength());
        System.out.println("From " + inPacket.getAddress() + " Msg : " + msg);
      }
    } catch (IOException ioe) {
      System.out.println(ioe);
    }
  }
}
