import java.io.*;
import java.util.*;
class Extract
{
 public static void main(String args[]) throws IOException
 {
  int ch;  
  FileInputStream fin = new FileInputStream(args[0]);
  FileOutputStream fout1 = new FileOutputStream("char.txt");
  FileOutputStream fout2 = new FileOutputStream("no.txt");
  FileOutputStream fout3 = new FileOutputStream("spc.txt");
  FileOutputStream fout4 = new FileOutputStream("dum.txt");
  while((ch=fin.read())!=-1)
  {
   if(((ch>=33)&&(ch<=47))||((ch>=91)&&(ch<=96))||((ch>=123)&&(ch<=126))||((ch>=58)&&(ch<=64)))
    fout3.write(ch);
   else if((ch>=48)&&(ch<=57))
    fout2.write(ch);
   else if(((ch>=65)&&(ch<=90))||((ch>=97)&&(ch<=122)))
    fout1.write(ch);
   else
    fout4.write(ch);
  }
 }
}
