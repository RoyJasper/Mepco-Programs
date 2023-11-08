import java.io.*;
import java.util.*;
class Timer extends Thread
{
int n=10;
public void run()
{
for(int i=n;i>0;i--)
{
try
{
Thread.sleep(500);
}
catch(InterruptedException e)
{
System.out.println(e);
}
System.out.println(i);
}
System.out.println("Time OUT");
}
public static void main(String args[])
{
Timer t=new Timer();
t.start();
}
}
