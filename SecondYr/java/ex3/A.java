package pack1;
import java.io.*;
import java.lang.*;
import java.util.*;
public class A extends Another
{
  static int a=10;
  public static int b=20;
  private static int c=30;
  protected static int d=40;

 public static void main(String args[]) throws IOException
 {
  System.out.println("FROM PACK1 IN OWN CLASS\n");
  System.out.println("VALUE OF A = "+a);
  System.out.println("VALUE OF B = "+b);
  System.out.println("VALUE OF C = "+c);
  System.out.println("VALUE OF D = "+d);
  access();
  }
  }
 class Another
 {
   public static void access()
   {
    System.out.println("FROM PACK1 IN ANOTHER CLASS\n");
    System.out.println("VALUE OF A = "+A.a);
    System.out.println("VALUE OF B = "+A.b);
 // System.out.println("VALUE OF C = "+A.c);   
    System.out.println("PRIVATE VARIABLE CANNOT ACCESED FROM ANOTHER CLASS");
    System.out.println("VALUE OF D = "+A.d);
   }
  }
