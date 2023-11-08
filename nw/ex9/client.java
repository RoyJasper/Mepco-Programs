import java.io.*;
import java.net.*;
public class client
{
    public static void main(String[] args)
    {
        MulticastSocket sock=null;
        DatagramPacket dgm=null;
        byte[] ib=new byte[256];
        try
        {
            sock=new MulticastSocket(4568);
            InetAddress ad=InetAddress.getByName("224.2.2.3");
            sock.joinGroup(ad);
            while(true)
            {
                dgm=new DatagramPacket(ib,ib.length);
                sock.receive(dgm);
                String msg=new String(ib,0,dgm.getLength());
                System.out.println("\nFrom "+dgm.getAddress()+" Jasper Sends\n"+" Message:"+msg);
            }
        }
        catch(IOException exp)
        {
            System.out.println(exp);
        }
    }
}


