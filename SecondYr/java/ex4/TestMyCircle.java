import java.io.*;
import java.util.*;
import java.lang.*; 
class Mycircle
{
 public int radius;
 public int x,y;

  Mycircle(int rad,int xx,int yy)
  {
   radius=rad;
   x=xx;
   y=yy;
   }
   public int getradius()
   {
    return radius;
    }
   public int getx()
   {
    return x;
   }
   public int gety()
   {
    return y;
    }
   public void setradius(int r)
   {
    this.radius=r;
    }
public void setcenter(int x,int y)
{
  this.x=x;
   this.y=y;
   }
public String tostring()
 {
  String s;
  s="CIRCLE"+"("+x+","+y+") RADIUS="+radius;
  return s;  
 }
public double getarea()
{
 double area;
  area=3.14*radius*radius;
   return area;
  }
}
public class Testmycircle extends Mycircle
{
 public static void main(String args[])
  {
   Mycircle(5,7,8);
   Mycircle obj=new Mycircle();
   String s;
   double area;
   obj.setradius(5);
   obj.setcenter(7,8);
   s=obj.tostring();
   System.out.println(""+s);
   area=obj.getarea();
   System.out.println("ARAE ="+area);
  }
 }
