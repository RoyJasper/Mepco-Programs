import java.io.*;
import java.util.*;
class Stringmanip
{
 public static void main (String args[]) throws IOException
 {
  String str="Welcome! This is 13IT452 Cource";
  System.out.println(str.toUpperCase());
  System.out.println(str.toLowerCase());
  int length=str.length();
  System.out.println("Length is "+length);
  int last=str.indexOf("Cource");
  System.out.println("Last index is "+last);
 } 
}
