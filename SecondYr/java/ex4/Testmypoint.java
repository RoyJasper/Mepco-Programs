import java.io.*;
import java.util.*;
class Mypoint
{
 int x;
 int y;
    Mypoint()
    {
     x=0;
     y=0;
     }
  Mypoint(int tempx,int tempy)
  {
   x=tempx;
   y=tempy;
   }
  public int getx()
  {
   return x;
   }
   public int gety()
  {
  return y;
   }

 public void setx(int x)
 {
  this.x=x;
   }

 public void sety(int y)
 {
  this.y=y;
   }

public void setxy()
 {
  System.out.println("ENTER VALUE FOR X,Y");
  Scanner obj=new Scanner(System.in);
  x=obj.nextInt();
  y=obj.nextInt();
  }
public String tostring()
{
 String s;
 s="( x , y) = ( "+x+","+y+" )";
 return s;
 }
public String distance1(int tx,int ty)
 {
  int c,d;
  String s1;
   c=this.x-tx;
   d=this.y-ty;
    s1="( x , y) = ( "+x+","+y+" )";
  return s1;
 }
public String distance(Mypoint another)
 {
   
   int a,b;
   another.setxy();
   a=this.x-another.x;
   b=this.y-another.y;
   String s="( x , y) = ( "+a+","+b+" )";;
   return s;
  }
  }
public class Testmypoint
{
 public static void main(String args[])
 {
  Mypoint obj=new Mypoint();
  obj.setx(5);
  obj.sety(7);
  System.out.println("AUTOSET POINT\n"+obj.tostring());
  obj.setxy();
  obj.distance1(5,7);
  Mypoint obj1=new Mypoint();
  System.out.println("DISTANCE BETWEEN POINTS"+obj.distance(obj1));
 }
}
