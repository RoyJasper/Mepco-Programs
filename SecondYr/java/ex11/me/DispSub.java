import java.io.*;
import java.util.*;
class SimpleThread extends Thread 
{   
    public SimpleThread(String str) 
    {
   
        super(str);
    }
    public void run() 
    {
        for (int i = 0; i <3; i++) 
    {
            System.out.println(i + " " + getName());
        }
    }
}
class DispSub {
    public static void main (String[] args) {
        new SimpleThread("DAA").start();
        new SimpleThread("DBMS").start();
        new SimpleThread("JAVA").start();
    }
}

