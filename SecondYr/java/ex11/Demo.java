import java.io.*;
import java.util.*;
class Demo extends Thread implements Runnable
{
public void run()
{
int i;
String c[]={"JAVA","DAA","Dbms","Data"};
for(i=0;i<4;i++)
{
System.out.println("The Subjects are .... "+c[i]);
}
}
public static void main(String args[])
{
Demo s=new Demo();
Thread t1=new Thread(s);
Thread t2=new Thread(s);
Thread t3=new Thread(s);
t1.start();
t2.start();
t3.start();
}
}

