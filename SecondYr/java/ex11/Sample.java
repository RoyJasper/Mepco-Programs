import java.io.*;
import java.util.*;
class Sample extends Thread
{
public void run()
{
int i;
for(i=0;i<5;i++)
{
System.out.println(i);
}
}
public static void main(String args[])
{
Sample s=new Sample();
Thread t1=new Thread(s);
Thread t2=new Thread(s);
t1.start();
t2.start();
}
}
