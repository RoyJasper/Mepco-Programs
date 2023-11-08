import java.io.*;
import java.util.*;
class Array
{
 public static void main (String args[]) throws IOException
 {
  int[] array=new int[10];
  int i,number,j,cond=0;
  System.out.println("Enter 10  numbers");
  Scanner obj=new Scanner (System.in);
  for(i=0;i<10;i++)
  {
    System.out.println("Enter  number");
    number=obj.nextInt();
   for(j=0;j<i;j++)
    {
     if(array[j]==number)
      {
      // cond=1;
       System.out.println("Reocurence");
       i--;
      }
    }
    if(cond==0)
    {
     array[i]=number;
     cond=0; 
    }
    }
     System.out.println(" Numbers are");
      for(j=0;j<10;j++)
      {
       System.out.println("\t"+array[j] );
      }
 }
}
