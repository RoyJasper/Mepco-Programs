import java.io.*;
import java.util.*;
import java.lang.*;
class Author 
   {
   private String name;
   private String email;
   private char gender;
 
   public Author(String name, String email, char gender)
   {
      this.name = name;
      this.email = email;
      this.gender = gender;
   }
   public String getName() 
   {
      return name;
   }
 
   public String getEmail() 
   {
      return email;
   }
 
   public char getGender() 
   {
      return gender;
   }
 
   public void setEmail(String email) 
   {
      this.email = email;
   }
 

   public String toString() 
   {
      return name + " (" + gender + ") at " + email;
   }
  }
public class TestAuthor
 {
   public static void main(String[] args) 
    {
      Scanner obj=new Scanner(System.in);
      String a,b,c,d;
      char e;
      System.out.println("ENTER NAME");
      a=obj.nextLine();
      System.out.println("ENTER EMAIL");
      b=obj.nextLine();
      System.out.println("ENTER SET EMAIL FOR "+a+" AS ");
      c=obj.nextLine();
      System.out.println("ENTER GENDER m,f");
      e=obj.next().charAt(0);
      //System.out.println("ENTER SET EMAIL FOR "+a+" AS ");
      //c=obj.nextLine();
      Author person = new Author(a,b,e);
      System.out.println(person);
      person.setEmail(c);
      System.out.println(person);  
   }
}
