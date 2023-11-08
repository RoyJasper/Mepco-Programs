import java.io.*;
import java.util.*;
import java.lang.*;
class person
{
 String name,address;
 int age;
 public String getname()
 {
  return name;
 }
 public void setname(String a)
 {
  name=a;
 }
 public int getage()
 {
  return age;
 }
 public void setage(int age)
 {
  this.age=age;
 }
 public String getaddress()
 {
  return address;
 }
 public void setaddress(String address)
 {
  this.address=address;
 }
}
class student extends person
{
 public int rno;
 public int getno()
 {
  return rno;
 }
 public void setno(int rno)
 {
  this.rno=rno;
 }
}
class teacher extends person
{
 String subject;
 int salary;
 public int getsalary()
 {
  return salary;
 }
 public void setsalary(int sal)
 {
  salary=sal;
 }
 public void setsubject(String sub)
 {
  subject=sub;
 }
 public String getsubject()
 {
  return subject;
 }
}
class collegestudent extends student
{
 int year;
 String major;
 public int getyear()
 {
  return year;
 }
 public void setyear(int year)
 {
  this.year=year;
 }
 public String getmajor()
 {
  return major;
 }
 public void setmajor(String maj)
 {
  major=maj;
 }
}
class starter
{
 public static void main(String args[]) throws IOException
 {
  Scanner obj=new Scanner(System.in);
  teacher t= new teacher();
  collegestudent c= new collegestudent();
  int age,rno,year,sal;
  String a,address,maj,sub,name;
  System.out.println("enter the age");
  age=obj.nextInt();
  System.out.println("enter the rollno");
  rno=obj.nextInt();
  System.out.println("enter the year");
  year=obj.nextInt();
  System.out.println("enter the salary");
  sal=obj.nextInt();
  System.out.println("enter the name");
  a=obj.nextLine();
  name=obj.nextLine();
  System.out.println("enter the address");
  address=obj.nextLine();
  System.out.println("enter the major");
  maj=obj.nextLine();
  System.out.println("enter the subject");
  sub=obj.nextLine();
  c.setname(name);
  c.setage(age);
  c.setaddress(address);
  c.setno(rno);
  c.setyear(year);
  c.setmajor(maj);
  t.setsubject(sub);
  t.setsalary(sal);
  System.out.println("name is:"+c.getname()+"\nroll no:"+c.getno()+"\nage:"+c.getage()+"\naddress:"+c.getaddress());
  System.out.println("\nmajor:"+c.getmajor()+"\nsubject:"+t.getsubject()+"\nyear:"+c.getyear()+"\nsalary:"+t.getsalary());
 }
}

