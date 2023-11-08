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
            u=(String)dis.toString();
            p=dis.readLine();
            fil=dis.readUTF();
            System.out.println("  "+u+"  "+p+"  "+fil);
              
        }  
            catch(Exception e)
            {
                System.out.println(e);
            }
     }
}
