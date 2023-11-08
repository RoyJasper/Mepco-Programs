import java.io.*;
import java.util.*;
class Countpar
{
 public static void main(String args[]) throws IOException
 {
  int ch,c=0;
  FileInputStream fin = new FileInputStream(args[0]);
  char chk =(char)args[1];
  while((ch=fin.read())!=-1)
  {
  // if(args[1].compareTo(ch)==0)
   if(chk==ch)
    c++;
  }
  System.out.println("No of "+args[1]+" are "+c );
 }
}
