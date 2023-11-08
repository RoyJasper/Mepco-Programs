import java.io.*;
import java.util.*;
class Problem1
{
int s=0,c=5;
String [] product = new String[5];
}
class Producer extends Problem1 implements Runnable
{
public void run()
{
while(s!=5)
{
Scanner in =new  Scanner(System.in);
if(c!=s)
{
System.out.println("Enter the Product");
product[s]=in.next();
s++;
System.out.println(s);
}
else
System.out.println("FULL");
}
}
}
class Consumer extends Producer implements Runnable
{
public void run()
{
s=5;
c=0;
while(s!=0)
{
if(c!=s)
{
s--;
System.out.println(s);
System.out.println("The Product is"+product[s]);
}
else
System.out.println("EMPTY");
}
}
}

class Problem
{
public static void main(String args[])
{
Producer p=new Producer();
Consumer c=new Consumer();
Thread p1=new Thread(p);
Thread c1=new Thread(c);
try
{
p1.start();
p1.join();
c1.start();
c1.join();
}
catch(InterruptedException e)
{
System.out.println(e);
}
}
}
