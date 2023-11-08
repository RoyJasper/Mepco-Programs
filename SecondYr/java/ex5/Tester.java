import java.io.*;
import java.util.*;
class customer
{
private String name;
private boolean member;
private String type;
public customer(String k,boolean m,String l)
{
name=k;
member=m;
type=l;
}
String getName()
{
return name;
}
String getType()
{
return type;
}
boolean isMember()
{
return  member;
}
String print()
{
return ((getName())+getType());
}}
class visit extends customer
{
private int ser;
private int exp;
private String date;
public visit(String n,boolean m,String l,int s,int e,String d)
{
super(n,m,l);
ser=s;
exp=e;
date=d;
}
String getDate()
{
return date;
}
int getExp()
{
return exp;
}
int getSer()
{
return ser;
}
int getTotexp()

{
return (exp*ser);
}

private int gold= 3;
private int silver= 2;
private int premium= 4;
private int pros= 1;
private int prog= 1;
private int prop= 5;
public  int  getDisser()
{
int f;
f=exp;
if(f>2000)
return (f/premium);
else if (f<1000)
return (f/silver);
else
return(f/gold);
}
public int  getDispro()
{
int f;
f=ser;
if(f>2000)
return (f/prop);
else if (f<1000)
return (f/pros);
else
return(f/prog);
}
String display()
{
return ("The Total Expenses is " + getTotexp());
}
String display1()
{
return ("The Service Expenses is " + getDisser());
}
String display2()
{
return ("The Product Expenses is " + getDispro());
}
}
class Tester
{
public static void main(String arg[])
{
String na,ty,da;
int ser,pro;
boolean me;
Scanner obj = new Scanner(System.in);
System.out.println("Enter the name");
na=obj.nextLine();
System.out.println("Enter the Type");
ty=obj.nextLine();
System.out.println("Enter the Whether a member or not");
me=obj.nextBoolean();
System.out.println("Enter the Service expences");
ser=obj.nextInt();
System.out.println("Enter the Product expences");
pro=obj.nextInt();
System.out.println("Enter the date");
da=obj.nextLine();
visit v= new visit(na,me,ty,ser,pro,da);
System.out.println(v.print());
System.out.println(v.display());
System.out.println(v.display1());
System.out.println(v.display2());
}}
