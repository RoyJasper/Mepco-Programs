package pack;
import java.io.*;
import java.util.*;
public class arithmetic extends addition
{
 /*
    1.ADDITION
    2.SUBTRATCTION
    3.MULTIPLICATION
   */

  }
 class addition extends subtraction
{
 public void sum()
 {
   int a,b,c=0;
   System.out.println("ENTER THE TWO NUMBERS");
   Scanner in=new Scanner(System.in);
   a=in.nextInt();
   b=in.nextInt();
   c=a+b;
   System.out.println("\nSUM IS  "+c);
   }
  }
 class subtraction extends product
{
 public void difference()
 {
  Scanner in=new Scanner(System.in);
  int a,b,c=0;
   System.out.println("ENTER THE TWO NUMBERS");
   a=in.nextInt();
   b=in.nextInt();
   c=a-b;
   System.out.println("\nDIFFERENCE IS "+c);
  }
}
 class product
{
 public void multiply()
 {
  Scanner in=new Scanner(System.in);
 int a,b,c=0;
 System.out.println("ENTER THE TWO NUMBERS");
 a=in.nextInt();
 b=in.nextInt();
 c=a*b;
 System.out.println("\nPRODUCT IS "+c);
 }
}
