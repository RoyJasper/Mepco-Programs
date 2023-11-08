import java.io.*;
import java.util.*;
class Random extends Thread
{
int n;
public void run()
{
n=(int) (Math.random()*100);
}
public int get()
{
return n;
}
public static void main(String args[])
{
Thread  t  = new Thread();
Random [] r = new Random[5];
int s=0,i;
for(i=0;i<5;i++)
t[i]=new Thread();
for(i=0;i<5;i++)
t[i].start();
for(i=0;i<5;i++)
t[i].join();
for(i=0;i<5;i++)
{
System.out.println("Thread is "+r[i].get());
s=s+t[i].get();
}
System.out.println("Sum is"+s);
}
}

