import java.io.*;
import java.util.*;
class Ran extends Thread
{
double n;
public void run()
{
n=Math.random();
n=0.3*100;
}
public double get()
{
System.out.println(n);
return n;
}
public static void main(String args[])
{
Ran r = new Ran();
double s=0;
int i;
r.start();
for(i=0;i<5;i++)
{
System.out.println("Thread is "+r.get());
s=s+r.get();
}
System.out.println("Sum is"+s);
}
}


