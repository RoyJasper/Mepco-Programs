import java.io.*;
import java.util.*;
class Sample extends Thread
{
int n;
Sample(int n)
{
this.n=n;
}
public void run()
{
int i;
for( i=2;i<n;i++)
{
if(n%i==0)
break;
}
if(n==i)
System.out.println("Prime");
else
System.out.println("Not a Prime");
}
}
class Sample1 implements Runnable
{
int n;
Sample1(int n)
{
this.n=n;
}
public void run()
{
int i;
for( i=2;i<n;i++)
{
if(n%i==0)
break;
}
if(n==i)
System.out.println("Prime");
else
System.out.println("Not a Prime");
}
}
class Prime
{
public static void main(String args[])
{
int p;
Scanner in =new Scanner(System.in);
System.out.println("Enter the Number");
p=in.nextInt();
Sample s=new Sample(p);
System.out.println("********BY THREAD************");
s.start();
Sample1 q=new Sample1(p);
Thread t=new Thread(q);
System.out.println("********BY RUNNABLE************");
t.start();
}
}
