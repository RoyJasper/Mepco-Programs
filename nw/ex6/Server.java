import java.io.*;
import java.util.*;
import java.net.*;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

class Server
{

    private static int port = 3404;


    public static void main(String args[])
    {
        try
        {
            final ExecutorService service = Executors.newCachedThreadPool();
            ServerSocket serversock=new ServerSocket(3204);
            while(true)
            {
                Socket  socket=serversock.accept();
                service.submit(new MyClass(socket));
            }
        }
        catch(IOException e) {}
    }
}

class MyClass implements Runnable
{

    Socket socket;

    public MyClass(Socket s)
    {
        socket = s;
    }

    public void run()
    {
        try
        {
            DataInputStream in = new DataInputStream(socket.getInputStream());
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
       			System.out.println("Enter a Number \n" );
						int x = in.readInt();
            out.write(2*x);
            socket.close();
        }
        catch(IOException e) {}
    }
}
