import java.io.*;
import java.lang.*;
import java.util.*;
class Person
{
 public int age;
 public String name;
 public Person(String n,int a)
 {
  name=n;
  age=a;
 }
 public int getage()
{
 return age;
}
public String getname()
{
 return name;
}
 public void check()
 {
  if(age<0)
   System.out.println("Enter crt age");
 else
{
  if(age<30)
   System.out.println("Young one");
  else if((age>30)&&(age<50))
   System.out.println("Middle age");
  else 
   System.out.println("Old");
}
 }
}
class Demo
{
 public static void main(String args[]) throws IOException
 {
  String a;
  a=args[0];
 if(a=isnumber(args[0]
)
   {
 System.out.println("Enter in crt order");
}
  Person p = new Person(args[0],Integer.parseInt(args[1]));
  int a1;
//  a1=p.parseInt(args[1]);
 // p.Person(args[0],args[1]);
  p.check();
 }
}
