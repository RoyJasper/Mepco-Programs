import java.io.*;
import java.util.*;
 class Student
{
 private String name,dept;
 private int rollno,spr;
  Student(String tname,String tdept,int trollno,int sprt)
  {
   name=tname;
   dept=tdept;
   rollno=trollno;
   spr=sprt;
   }
  public String getname()
  {
   return name;
   }
  public String getdept()
  {
   return dept;
   }
  public int getrollno()
  {
   return rollno;
   }
  public int getspr()
  {
   return spr;
    }
}
  interface Sports
  {
   int mark=5;
   void Sportsmark();
   }
  
class Exam //extends Student
{
// Student objs= new Student();
 public int rno,totale;
 int m[]=new int[6];
 private String name;

 public void setmarks(int tmarks[])
 {
 
   for(int i=0;i<6;i++)
   {
    m[i]=tmarks[i];
   // System.out.println(""+totale);
    }
   }
  public int gettotale()
  {
    for(int i=0;i<6;i++)
   {
  totale=totale+m[i];
  }
   return totale;
   }
  }
 class Result  extends Exam implements Sports
 {
  public int tot;
 public void Sportsmark()
 {
  System.out.println("SPORTS MARK =5");
  }
    public int getsum(Student ts,Exam te,int sp)
    {
     int a,b=0,c;
     a=te.gettotale();
     System.out.println(""+a);
     if(sp==1)
     b=Sports.mark;
     c=a+b;
     if(c>60)
     c=60;
     else
     c=a;
     tot=c;
   return tot;
     }
  
    public int gettotal()
    {
     return tot;
    
    }
}
 public class Drive
 {
   public static void main(String args[])
   {
    int rol,sum,sp;
    int mar[]=new int[6];
    String nam,dep;
    Result r=new Result();
    Scanner obj=new Scanner(System.in);
    System.out.println("ENTER NAME ROLLNO DEPT SPORTS PERSON=1 or 0");
    nam=obj.nextLine();
   //ol=obj.nextInt();
    dep=obj.nextLine();
    rol=obj.nextInt();
    sp=obj.nextInt();
    System.out.println("ENTER 6 MARKS FOR THE STUDENT");            
    for(int i=0;i<6;i++)
    mar[i]=obj.nextInt();
    Student s=new Student(nam,dep,rol,sp);
    Exam e=new Exam();
    r.setmarks(mar);
    
    sum=r.getsum(s,e,sp);
   System.out.println("MARK OBJAINED BY STUDENT="+sum);
  }
 }
                                                                             
