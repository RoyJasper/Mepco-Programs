import java.io.*;
import java.util.*;
import java.lang.*;
class Volume
{
 public static void main(String args[])
 {
  double die,distance=0.0,area=0.0;
  int choice,radius,x1,x2,y1,y2;
  Scanner obj=new Scanner(System.in);

  System.out.println("ENTER YOUR CHOICE\n1.VOLUME OF SPHERE\n2.DISTANCE BETWEEN TWO POINTS\n3.STIMULATING DIE");
  choice=obj.nextInt();
switch(choice)
{
 case 1:
        System.out.println("ENTER RADIUS \n");
        radius=obj.nextInt();
        area=4*Math.PI*radius*radius*radius/3;
        System.out.println("VOLUME OF SPHERE =\n"+area);
        break;
 case 2:
      System.out.println("ENTER FROM POINTS as (x,y)");
      x2=obj.nextInt();
      y2=obj.nextInt();
      System.out.println("ENTER TO POINTS as (x,y)");
      x1=obj.nextInt();
      y1=obj.nextInt();
      distance=Math.sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
      System.out.println("DISTANCE BETWEEN POINTS IS  "+distance);
      break;
 case 3:
      die=Math.random()*7;
      int a=(int)die;
      if(a!=0)
      System.out.println("YOUR TURN GIVES  "+a);
      break;
   }
  }
 }
