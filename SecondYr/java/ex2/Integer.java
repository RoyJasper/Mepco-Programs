import java.io.*;
import java.util.*;
class Integer
{
 public static void main (String args[]) throws IOException
 {
  int[] array={10,6,88,91,25,77,14,23,4,235};
  int size=array.length;
	int i;
  float aver=0;
  System.out.println("Length is "+size);
  System.out.println("5 th element is  "+array[4]);
  array[4]=35;
  for(i=0;i<size;i++)
    {
     System.out.println(array[i]);
    } 
 for(i=0;i<size;i++)
    {
     aver=aver+array[i];
    }
   aver=aver/10;
   System.out.println("Average  is "+aver);
 }
} 
