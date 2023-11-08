import java.io.*;
import java.util.Vector;
import java.util.Scanner;
class VectorExample
{
public static void main(String args[])
{
int a,b,c,d,x;
Vector ob = new Vector ();
Scanner obj=new Scanner (System.in);
while(true)
{
System.out.println("\nEnter the Choice \n1.Add \n2.Remove \n3.Get \n4.Clear \n5.Retrieve");
a=obj.nextInt();
switch(a)
{
case 1:
System.out.println("\nEnter the Element to be inserted");
b=obj.nextInt();
ob.add(b);
break;
case 2:
System.out.println("\nEnter the Position");
c=obj.nextInt();
System.out.println("The Removed Element is :"+(ob.remove(c)));
break;
case 3:
System.out.println("\nEnter the Position to be Retreived");
x=obj.nextInt();
System.out.println("The element at"+ x +"is"+(ob.get(x)));
break;
case 4:
ob.clear();
break;
case 5:
for(int j=0;j<ob.size();j++)
System.out.println(ob.get(j));
break;
}}}}

