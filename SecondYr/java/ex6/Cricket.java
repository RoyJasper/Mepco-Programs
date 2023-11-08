import java.io.*;
import java.util.*;
class Cricket
{
public static void main(String args[])
{
int sc,f,i;
String n,c,e;
Scanner obj=new Scanner(System.in);
Scanner obj1 = new Scanner(System.in);
HashMap <String,Integer> ob=new HashMap<String,Integer>();
System.out.println("Enter the number of men:");
int a=obj.nextInt();
for(i=0;i<a;i++)
{
System.out.println("Enter the name and Score:");
n=obj1.nextLine();
sc=obj.nextInt();
ob.put(n,sc);
}
System.out.println("Enter the name to be present or not\n");
e=obj1.nextLine();
System.out.println("The score is "+(ob.get(e)));
}}

