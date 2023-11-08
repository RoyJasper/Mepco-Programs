import java.io.*;
import java.util.*;
import java.net.*;
public class server
{
    public static void main(String[] args)
    {
        DatagramSocket sock=null;
        DatagramPacket dgm=null;
        byte[] byt;
        Scanner sc=new Scanner(System.in);
        final int PORT=4568;
        try
        {
            sock=new DatagramSocket();
            long c=0;
            String msg;
            do
            {
                System.out.println("\nEnter the message to be transmitted:");
                msg=sc.next();
                byt=msg.getBytes();
                InetAddress ad=InetAddress.getByName("224.2.2.3");
                dgm=new DatagramPacket(byt,byt.length,ad,PORT);
                sock.send(dgm);
                System.out.println("Message Sent:"+msg);

            }
            while(!msg.equals("stop"));
        }
        catch(IOException exp)
        {
            System.out.println(exp);
        }
    }
}


