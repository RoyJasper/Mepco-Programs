import java.io.*;
import java.util.*;
class Circle
{
 double radius;
 String color;

 Circle()
 {
  radius=0;
  color="red";
  }
 Circle(int rad,String colour)
 {
  this.radius=rad;
  this.color=colour; 
  }
 public double getradius()
 {
  System.out.println("ENTER RADIUS");
  Scanner obj=new Scanner(System.in);
   radius=obj.nextDouble();
   return radius;
  }
public String getcolor()
 {
 System.out.println("ENTER COLOR");
 Scanner obj=new Scanner(System.in);
 color=obj.nextLine();
 return color;
 }
public double getarea()
 {
  return (3.14*radius*radius);
  }
}
public class Testcc
{
 public static void main(String args[])
 {
   double a,area;
   String colour;
   Circle c=new Circle();
   area=c.getarea();
   System.out.println("DEFAULT AREA OF "+c.color+" CIRCLE IS  "+area);
   a=c.getradius();
   colour=c.getcolor();
   area=c.getarea();
   System.out.println("AREA OF "+colour+" CIRCLE IS  "+area);
  }
  }
