import java.io.*;
import java.util.*;
class Random1 extends Thread
{
int n;
public void run()
{
n=Math.random()*100;
}
public int get()
{
return n;
}
public static void main(String args[])
{
Random r = new Random();
int s=0,i;
for(i=0;i<5;i++)
r.start();
for(i=0;i<5;i++)
r.join();
for(i=0;i<5;i++)
{
System.out.println("Thread is "+r.get());
s=s+r.get();
}
System.out.println("Sum is"+s);
}
}

