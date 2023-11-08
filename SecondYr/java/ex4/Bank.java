import java.io.*;
import java.util.*;
class Account
{
public double bal;
public int acc;
public void deposit(double sum)
{
if(sum>0)
bal=bal+sum;
else
System.out.println("Cannot Deposit");
}
public void withdraw(double sum)
{
if((bal-sum)>0)
bal=bal-sum;
else
System.out.println("Error!!!!");
}
public double getbal()
{
return bal;
}
public int getacc()
{
return acc;
}
public void setbal(double a)
{
System.out.println(a);
bal=a;
}
public void setacc(int a)
{
acc=a;
}
public String toString()
{
return ("accountno:"+acc+"\n"+"balance:"+bal+"\n");
}
public   void print()
{
System.out.println(toString());
}
}
class Savings extends Account
{
private int interest;
public void setInterest(int a)
{
interest=a;
}
public int getInterest()
{
return interest;
}
public String toString()
{
return ("accountno:"+acc+"\n"+"balance:"+bal+"\n"+"Interest:"+interest+"\n");
}
public  void print()
{
System.out.println(toString());
}
}
class Current extends Account
{
private int over;
public void setOver(int a)
{
over=a;
}
public int getOver()
{
return over;
}
public String toString()
{
return ("accountno:"+acc+"\n"+"balance:"+bal+"\n"+"over_draft_limit:"+over+"\n");
}
public  void print()
{
System.out.println(toString());
}
}
class Bank
{
public static void main(String arg[]) throws IOException
{
int s,f;
double d;
Scanner obj = new Scanner(System.in);
Scanner ob = new Scanner(System.in);
Savings sa=new Savings();
for(int i=0;i<2;i++)
{
System.out.println("enter the accno , balance , interest");
s=obj.nextInt();
d=obj.nextDouble();
f=obj.nextInt();
sa.setacc(s);
sa.setbal(d);
sa.setInterest(f);
System.out.println("enter the amount to be deposited");
f=obj.nextInt();
sa.deposit(f);
System.out.println("enter the amount to be withdrawn");
f=obj.nextInt();
sa.withdraw(f);
System.out.println("The accno , balance , interest");
sa.print();
}
}
}

