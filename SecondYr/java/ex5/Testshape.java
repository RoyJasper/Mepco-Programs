import java.io.*;
import java.util.*;
 abstract class Shape
{
  private String color;
  private boolean filled;
  Shape()
  {
  color="";
  filled=false;
   }
  Shape(String tcolor,boolean tfilled)
  {
   color=tcolor;
    filled=tfilled;
   }
public String getcolor()
{
 return color;
  }
public boolean isfilled()
{
 return filled;
  }
public void setcolor(String tcolor)
{
  this.color=tcolor;
  }
public void setfilled(boolean tfilled)
{
  this.filled=tfilled;
   }
public abstract double getarea();
public abstract double getperimeter();
public abstract String tostring();
}
class Circle extends Shape
{
 double radius;
 Circle()
 {
  radius=0.0;
  }
 Circle(double tr)
 {
  radius=tr;
  }
 Circle(double tr,String tcolor,boolean tfilled)
 {
  super(tcolor,tfilled);
  radius=tr;
  }
  public double getradius()
  {
   return radius;
   }
  public void setradius(double tr)
  {
   this.radius=tr;
   }
  public double getarea()
  {
    return 2*3.14*radius*radius;
    }
   public double getperimeter()
   {
    return 2*3.14*radius;
    }
   public String tostring()
   {
    return ("CIRCLE");
   }
}

class Rectangle extends Shape
{
 double length,width;
 Rectangle()
 {
  length=0.0;
  width=0.0;
  }
 Rectangle(double tl,double tw)
 {
  length=tl;
  width=tw;
  }
 Rectangle(double tl,double tw,String tcolor,boolean tfilled)
 {
  super(tcolor,tfilled);
  length=tl;
  width=tw;
  }
  public double getlength()
  {
   return length;
   }
  public double getwidth()
  {
   return width;
   }
  public void setwidth(double tr)
  {
    this.width=tr;
   }
  public void setlength(double tr)
  {
   this.length=tr;
   }
  public double getarea()
  {
    return length*width;
    }
   public double getperimeter()
   {
    return (2*(length+width));
    }
   public String tostring()
   {
    return ("RECTANGLE");
   }
}
class Square extends Rectangle
{
 double side;
 
 Square()
 {
  side=0.0;
  }
 Square(double tr)
 {
  side=tr;
  }
 Square(double tr,String tcolor,boolean tfilled)
 {
  //super(tcolor,tfilled);
  side=tr;
  }
  public double getside()
  {
   return side;
   }
  public void setside(double tr)
  {
   this.side=tr;
   }
  public double getarea()
  {
    return side*side;
    }
   public double getperimeter()
   {
    return 4*side;
    }
   public String tostring()
   {
    return ("SQUARE ");
   }
}
public class Testshape
{
 public static void main(String args[])
  {
   double width,length,a,radius;
   int choice;
   Scanner obj=new Scanner(System.in);
   do
      {
        System.out.println("ENTER YOUR CHOICE \n1.CIRCLE\n2.RECTANGLE\n3.SQUARE\n4.EXIT");
        choice=obj.nextInt();
 switch(choice)
 {
    case 2:
       System.out.println("Enter length and breadth");
       length=obj.nextDouble();
       width=obj.nextDouble();
       Shape rectangle =new Rectangle(length,width);
       System.out.println("Rectangle width: " + width + " and length: " + length
                + "\narea: " + rectangle.getarea()
                + "\nperimeter: " + rectangle.getperimeter() + "\n");
       break;
       
    case 1:
        System.out.println("Enter Radius");
        radius=obj.nextDouble();
        Shape circle=new Circle(radius);
        System.out.println("Circle radius: " + radius
            + "\nArea: " + circle.getarea()
            + "\nPerimeter: " + circle.getperimeter() + "\n");
        break;
    case 3:
         System.out.println("Enter side");
         a=obj.nextDouble();
         Shape square=new Square(a);
         System.out.println("Square side: " + a 
                + "\n Area: " + square.getarea()
                + "\n Perimeter: " + square.getperimeter() + "\n");
        break;
    case 4:
         System.exit(0);	
    }
   }
  while(true);
 }
}
