import java.io.*;
import java.util.*;
import java.lang.*;
class time
{
 int h,m,s;
 int h1,m1,s1;
 public void sethour(int hr)
 {
  h=hr;
 }
 public void setminute(int min)
 {
  m=min;
 }
 public void setsecond(int sec)
 {
  s=sec;
 }
 public int gethour()
 {
  return h;
 }
 public int getminute()
 {
  return m;
 }
 public int getsecond()
 {
  return s;
 }
 public void nexthour()
 {
  if(h==23)
  h=0;
  else
  h++;
 }
 public void nextminute()
 {
  if(m==59)
  {
   h+=1;
   m=0;
  }
  else
  m++;
 }
 public void nextsecond()
 {
  if(s==59)
  {
   m+=1;
   s=0;
  }
  else
  s++;
 }
 public void prevhour(int hr)
 {
  h1=hr;
  if(h1==0)
  h1=23;
  else
  h1--;
 }
 public void prevminute(int min)
 {
  m1=min;
  if(m1==0)
  {
   m1=59;
   h1--;
  }
  else
  m1--;
 }
 public void prevsecond(int sec)
 {
  s1=sec;
  if(s1==0)
  {
   s1=59;
   m1--;
  }
  else
  s1--;
 }
 public void tostring()
 {
  System.out.println("Hour:"+h+"\nminute:"+m+"\nsecond:"+s);
 }
 public void tostring1()
 {
  System.out.println("Hour:"+h1+"\nminute:"+m1+"\nsecond:"+s1);
 }
}
class Demo
 {
 public static void main(String args[])throws IOException
 {
  time t=new time();
  int hr,min,sec;
  Scanner obj=new Scanner(System.in);
  System.out.println("enter the hour");
  hr=obj.nextInt();
  System.out.println("enter the minute");
  min=obj.nextInt();
  System.out.println("enter the second");
  sec=obj.nextInt();
  t.sethour(hr);
  t.setminute(min);
  t.setsecond(sec);
  t.nexthour();
  t.nextminute();
  t.nextsecond();
  System.out.println("next time is");
  t.tostring();
  t.prevhour(hr);
  t.prevminute(min);
  t.prevsecond(sec);
  System.out.println("previous time is");
  t.tostring1();
}
}
