import java.io.*;
import java.util.*;
import java.lang.*;
class circle
{
 private double l;
 private String c;
 public circle()
 {
   l=10;
  String c="red";
 }
 public circle(double l,String c)
 {
  this.l=l;
  this.c=c;
 }
 public double getradius()
 {
  return l;
 }
 public double getarea()
 {
  return(3.14*l*l);
 }
}
class testcircle
{
 public static void main (String args[]) throws IOException
 {
  double l;
  String c;
  Scanner obj=new Scanner(System.in);
  System.out.println("enter the radius value");
  l=obj.nextDouble();
  System.out.println("enter the colour");
  c=obj.nextLine();
  circle c1=new circle(l,c);
  System.out.println("radius is:"+c1.getradius());
  System.out.println("\narea is:"+c1.getarea());
 }
}

