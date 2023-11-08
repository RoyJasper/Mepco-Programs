import java.io.*;
import java.util.*;
class MyClass <T extends Number>
{
public void add ( T a,T b)
{
System.out.println("ADDITION :"+(a.doubleValue()+b.doubleValue()));
}
public void Sub ( T a,T b)
{
System.out.println("SUBTRACTION :"+(a.doubleValue()-b.doubleValue()));
}
public void Mul ( T a,T b)
{
System.out.println("MULTIPLICATION :"+(a.doubleValue()*b.doubleValue()));
}
}
class Myclass
{
public static void main(String args[])
{
Scanner in=new Scanner(System.in);
MyClass <Integer> a = new MyClass<Integer> ();
MyClass <Float> c = new MyClass<Float> ();
int x1,x2;
float y1,y2;
System.out.println("\nEnter the Two Numbers As Integer");
x1=in.nextInt();
x2=in.nextInt();
System.out.println("\nEnter the Two Numbers As Float");
y1=in.nextFloat();
y2=in.nextFloat();
a.add(x1,x2);
c.add(y1,y2);
a.Sub(x1,x2);
a.Mul(x1,x2);
c.Sub(y1,y2);
c.Mul(y1,y2);
}}

