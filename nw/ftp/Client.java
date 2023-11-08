package FTP;
import java.io.*;
import java.net.*;
import java.util.Scanner;
public class Client 
{
	 @SuppressWarnings("unused")
	public static void main(String[] args)
	    {
	    	int no;
	    	String u,p,fil;
			DataInput res = null;
	        try
	        {
	            Socket s=new Socket("localhost",2486);
	            DataOutputStream dout=new DataOutputStream(s.getOutputStream());
	            DataInputStream dis=new DataInputStream(s.getInputStream());
	            Scanner in=new Scanner(System.in);
	            System.out.println("Enter User Name : ");
	            u=in.next();
	            System.out.println("Enter User Password : ");
	            p=in.next();
	            System.out.println("Enter File name : ");
	            fil=in.next();
	            dout.writeChars(u);
	            dout.writeChars(p);
	            dout.writeChars(fil);
	            loop:
	            DataInputStream.readUTF(res);
	            if(res.equals("Failure"))
	            {
	            	System.out.println(" Auchorisatoin Failure \nEnter User Name : ");
		            u=in.next();
		            System.out.println("Enter User Password : ");
		            p=in.next();
		            System.out.println("Enter File name : ");
		            fil=in.next();
		            dout.writeChars(u);
		            dout.writeChars(p);
		            dout.writeChars(fil);
		            //goto loop;
	            }
	            if(res.equals("TotalFailure"))
	            {
	            	System.out.println("Total Failure");
	            	System.exit(0);
	            }
	            dout.flush();
	            dout.close();
	            s.close();
	            
	        }
	        catch(Exception e)
	        {
	            System.out.println(e);
	        }
	    }

}
