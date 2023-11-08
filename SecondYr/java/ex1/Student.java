import java.io.*;
import java.util.*;
class Student
{
 public static void main (String args[]) throws IOException
 {
  int quiz,midterm,finalscore;
  float percentage;
  InputStreamReader obj1=new InputStreamReader(System.in);
  BufferedReader obj=new BufferedReader(obj1);
  System.out.println("Enter quiz,midterm and final scores");
  quiz=Integer.parseInt(obj.readLine());
  midterm=Integer.parseInt(obj.readLine());
  finalscore=Integer.parseInt(obj.readLine());
  percentage=((quiz+midterm+finalscore)/3);
  System.out.println("Average is "+percentage);
  if(percentage>=90)
    System.out.println("Grade is A ");
 else  if((percentage>=70)&&(percentage<90))
    System.out.println("Grade is B ");
 else  if((percentage>=50)&&(percentage<70))
    System.out.println("Grade is C ");
 else
   System.out.println("Grade is F ");
 }
}
