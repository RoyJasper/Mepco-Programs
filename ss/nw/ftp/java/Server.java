package FTP;
import java.io.*;
import java.net.*;

public class Server 
{
	@SuppressWarnings("deprecation")
	public static void main(String[] args)
    {
		String u,p,fil;
		int cou=0;
        try
        {
        	ServerSocket ss=new ServerSocket(2486);
            Socket s=ss.accept();
            DataInputStream dis=new DataInputStream(s.getInputStream());
            DataOutputStream dout=new DataOutputStream(s.getOutputStream());
            u=DataInputStream.readUTF(null);
            p=DataInputStream.readUTF(null);
            fil=DataInputStream.readUTF(null);
            System.out.println("  "+u+"  "+p+"  "+fil);
              
        }  
            catch(Exception e)
            {
                System.out.println(e);
            }
     }
}
