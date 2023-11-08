import java.io.*;
import java.util.*;
class ListClass
{
public static void main(String args[])
{
int i,j,k;
Scanner obj=new Scanner(System.in);
ArrayList <Integer> al=new ArrayList <Integer> ();
int [] a =new int[5];
for(i=0;i<5;i++)
{
System.out.println("Enter the Number:");
a[i]=obj.nextInt();
al.add(a[i]);
}
System.out.println("Enter the Element to be get");
k=obj.nextInt();
j=al.get(k);
System.out.println(j);
ListIterator <Integer> litr = null;
litr=al.listIterator();

System.out.println("Elements in forward directiton"); 
while(litr.hasNext())
{
 System.out.println(litr.next()); 
} 
System.out.println("Elements in backward directiton"); 
while(litr.hasPrevious())
{
 System.out.println(litr.previous()); 
}
}}

