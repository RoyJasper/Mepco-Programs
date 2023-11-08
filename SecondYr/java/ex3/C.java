import pack.*;
import java.io.*;
import java.util.*;
class C
{
 public static void main(String []args)
  {
  int choice;
  do
  {
   System.out.println("ENTER YOUR CHOICE\n1.ADD\n2.SUB\n3.MULTIPLY\n4.EXIT");
   Scanner in=new Scanner(System.in);
   choice=in.nextInt();
   Arithmetic s=new Arithmetic();
   switch(choice)
   {
     case 1:
          s.sum();
          break;
        //  subtraction d=new subtraction();
     case 2:
          s.difference();
          break;
          //product m=new product();
      case 3:
          s.multiply();
          break;
         }
        }
     while(choice<4);
    }
 }

