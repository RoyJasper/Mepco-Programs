import java.io.*;
import java.util.*;
class Replace
{
 public static void main (String args[]) throws IOException
 {
  String str="I'm a JaVa PrOgRaMmeR";
  int i,r=0;
  int n=str.length();
  System.out.println(n);
  for(i=0;i<n;i++)
   {
    if(str.charAt(i)=='M'||str.charAt(i)=='m')
    {
     if(r!=3)
      {
      str=str.replace(str.charAt(i),' ');
       r++;
      }
    }
   }
  System.out.println(str);
 }
}
