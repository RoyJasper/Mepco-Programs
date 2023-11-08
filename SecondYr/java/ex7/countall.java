import java.io.*;
import java.util.*;
class Command
{
 public static void main(String args[]) throws IOException
 {
  int ch,l=0,w=0,c=0,vov=0;
  char chara;
  FileInputStream fin = new FileInputStream(args[0]);
  while((ch=fin.read())!=-1)
  {
   chra=(char)ch;
   if(chara==" ")
    w++;
   else if(chara.compareTo("\n"))
   {
    l++;
    w++;
   }
   else if((chara=='a')||(chara=='o')||(chara=='i')||(chara=='e')||(chara=='u'))
   {
    vov++;
    c++;
   }
   else
    c++;
  }
  System.out.println(" No of char,vowels,lines,words are"+c+" "+vov+" "+l+" "+w);
 }
}
