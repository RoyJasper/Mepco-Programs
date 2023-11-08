import java.io.*;
import java.util.*;
class Command
{
 public static void main(String args[]) throws IOException
 {
  int ch;
  char character;
  switch(args.length)
  {
   case 1:
    FileInputStream fin = new FileInputStream(args[0]);
    while((ch=fin.read())!=-1)
    {
     character=(char)ch;
     System.out.print(character);
    }
     break;
   case 3:
    if(args[2]==">")
     {
      FileInputStream fin1 = new FileInputStream(args[0]);
      FileOutputStream fout = new FileOutputStream(args[2]);
      while((ch=fin1.read())!=-1)
       fout.write(ch);
     }
     if(args[2].compareTo(">>")==0)
     {
      FileInputStream fin2 = new FileInputStream(args[0]);
      FileOutputStream fout2 = new FileOutputStream(args[2],true);
      while((ch=fin2.read())!=-1)
       fout2.write(ch);
     }
     else
      System.out.print("Error");
     break;
   default:
     System.out.print("Error");
     break;
  }
 }
}
