import java.io.*;
import java.util.*;
class Revenue
{
 public static void main (String args[]) throws IOException
 {
  int quantity,revenue,unitprice;
  int discount,temp,disc=0;
  InputStreamReader obj1=new InputStreamReader(System.in);
  BufferedReader obj=new BufferedReader(obj1);
  System.out.println("Enter quantity");
  quantity=Integer.parseInt(obj.readLine());
  System.out.println("Enter price");
  unitprice=Integer.parseInt(obj.readLine());
  temp=unitprice*quantity;
  if((quantity>=100)&&(quantity<=120))
  {
   disc=((temp*10)/100);
   discount=10;
  }
  else if(quantity>120)
  {
   disc=((temp*15)/100);
   discount=15;
  }
  else
   discount=0;
  temp=temp-disc;
  System.out.println("The revenue from sale : "+temp+"$");
  System.out.println("After discount amount : "+disc+" Discount "+discount+"%");
 
 }
}

