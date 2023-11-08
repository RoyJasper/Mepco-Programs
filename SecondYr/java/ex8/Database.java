import java.io.*;
import java.sql.*;
import java.util.*;
Class Database
{
 static final String JDBC_DRIVER="com.mysql.jdbc.Driver";
 static final String DB_URL="jdbc:mysql://localhost/blood";
 static final String user="system";
 static final String pass="jas";
 public static void main(String args[]) throws IOException SQLException
 {
  int cho,pbp=20000,pgp=15000,apbp=18000,apgp=13000,assobp=10000,assogp=8000,phra=22000,aphra=16000,assohra=12000;
  Class.forName(JDBC_DRIVER);
  System.out.println("Connected to database");
  Connection con=DriverManager.getConnection(JDB_URL,user,pass);
  Scanner obj=new Scanner(System.in);
  while(true)
  {
   System.out.println("Enter choice \n 1.Insert \n 2.Display \n 3. Modify \n");
   cho=obj.nextInt();
   switch(cho)
   {
    case 1:
      PreparedStatement ps=PrepareStatement("insert into myemp values(?,?,?,?,?,?,?,?,?,?)");
      System.out,println("Enter id,name,adress,desig,exp");
      int id=obj.nextInt();
      String name=obj.nextLine();
      String add=obj.nextLine();
      String desig=obj.nextLine();
      int exp=obj.nextInt();
     // int salary=obj.nextInt();
      ps.setInt(1,id);
      ps.setString(2,name);
      ps.setString(3,desig);
      ps.setString(5,add);
      ps.setInt(4,exp);
    //  ps.setInt(11,sal);
      if(desig.isEqual("prof"))
       {
        ps.setInt(6,pbp);
        ps.setInt(7,pgp);
        ps.setInt(8,phra);
        int ts=((pbp+pgp)+((pbp+pgp)*(0.7*pbp))/100);
        ps.setInt(9,(0.7*pbp));
        ps.setInt(10,((ts*12)/100));
        ps.setInt(11,(ts-((ts*12)/100)));
       }
   }
  }
 }
}
