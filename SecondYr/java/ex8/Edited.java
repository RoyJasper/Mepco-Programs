import java.io.*;
import java.sql.*;
import java.util.*;
class Employee
{
  static final String jdbc_driver="com.mysql.jdbc.Driver";
  static final String db_url="jdbc:mysql://localhost/mydata";
  static final String user="root";
  static final String pass="";
  public static void main(String [] args) throws IOException,SQLException,ClassNotFoundException
  {
    Scanner in=new Scanner(System.in);
    Class.forName(jdbc_driver);
    Connection conn=DriverManager.getConnection(db_url,user,pass);
    String s,address,name,designation,sql,value2="";
    float da,hra,pf,total,value3=0,ts;
    int id,gradepay,experience,basicpay,choice,c,value4=0;
while(true)
{
    System.out.println("1.Insert 2.Modify 3.Delete 4.Display 5.Exit Enter your choice");
    choice=in.nextInt();
  switch(choice)
  {
    case 1:
      Statement ps=conn.createStatement();
      while(true)
      {
        System.out.println("IF YOU WANT TO INSERT PRESS 'Y' ELSE PRESS 'N'");
        s=in.next();
        if(s.equals("y"))
        {
          System.out.println("ENTER THE EMPLOYEE ID(USE NUMBERS ONLY)");
          id=in.nextInt();
          System.out.println("ENTER THE EMPLOYEE NAME");
          name=in.next();
          System.out.println("ENTER THE EMPLOYEE ADDRESS");
          address=in.next();
          System.out.println("ENTER THE EMPLOYEE DESIGNATION");
          designation=in.next();
          System.out.println("ENTER THE EMPLOYEE EXPERIENCE");
          experience=in.nextInt();
          da=setda(designation);
     		hra=sethra(designation);
          basicpay=setsalary(designation);
	gradepay=setpay(designation);
	da=((basicpay+gradepay)*da)/100;
	ts=basicpay+gradepay+da+hra;
	pf=(ts*12)/100;
          total=ts-pf;
          sql="insert into employee (empid,empname,address,designation,experience,basicpay,gradepay,da,hra,pf,totalsalary,salary) values('"+id+"','"+name+"','"+address+"','"+designation+"','"+experience+"','"+basicpay+"','"+gradepay+"','"+da+"','"+hra+"','"+pf+"','"+ts+"','"+total+"');";
	  int i=ps.executeUpdate(sql);
	if(i==1)
	System.out.println("INSERTED SUCCESSFULLY");
	else
	System.out.println("NOT INSERTED");
        }
	else
	  break;
      }
     break;
	case 2:
		int value1=0;
		sql="";
		Statement st2=conn.createStatement();
		System.out.println("1.empid");
		 System.out.println("2.empname");
		 System.out.println("3.address");
		 System.out.println("4.desigantion");
		 System.out.println("5.experience");
		System.out.println("ENTER WHICH COLUMN NUMBER  BE UPDATE");
		c=in.nextInt();
		s=setname(c);
		System.out.println("ENTER WHICH VALUE SHOULD BE MODIFIED");
		if(c==1||c==5)
			value1=in.nextInt();
		else if(c==2||c==3||c==4)
			value2=in.next();
                System.out.println("ENTER EMPLOYEE ID VALUE SHOULD BE CHECK");
                 value4=in.nextInt();
		 if(c==1||c==5)
		sql="update employee set "+s+"='"+value1+"' where empid="+value4+";";
		else if(c==2||c==3||c==4)
		sql="update employee set "+s+"='"+value2+"' where empid="+value4+";";
		int j=st2.executeUpdate(sql);
		if(c==4)
		{
		da=setda(value2);
          	hra=sethra(value2);
          	basicpay=setsalary(value2);
        gradepay=setpay(value2);
        da=((basicpay+gradepay)*da)/100;
        ts=basicpay+gradepay+da+hra;
        pf=(ts*12)/100;
          total=ts-pf;
		sql="update employee set da='"+da+"' where empid="+value4+";";
		j=st2.executeUpdate(sql);
		sql="update employee set hra='"+hra+"' where empid="+value4+";";
		j=st2.executeUpdate(sql);
 		sql="update employee set pf='"+pf+"' where empid="+value4+";";
		j=st2.executeUpdate(sql);
		sql="update employee set basicpay='"+basicpay+"' where empid="+value4+";";
		j=st2.executeUpdate(sql);
		sql="update employee set salary='"+total+"' where empid="+value4+";";
		j=st2.executeUpdate(sql);
		sql="update employee set gradepay='"+gradepay+"' where empid="+value4+";";
		j=st2.executeUpdate(sql);
		sql="update employee set totalsalary='"+ts+"' where empid="+value4+";";
		j=st2.executeUpdate(sql);
		}
		if(j==1)
		System.out.println("MODIFIED SUCCESSFULLY");
		else
		System.out.println("NOT MODIFIED");
		break;
	case 3:
                Statement st1=conn.createStatement();
                System.out.println("ENTER EMPLOYEE ID VALUE SHOULD BE DELETE");
                 value4=in.nextInt();
                sql="delete from employee where empid="+value4+";";
                              int k=st1.executeUpdate(sql);
		System.out.println("DELETED SUCCESSFULLY");
                                      break;
		
	case 4:
		Statement st=conn.createStatement();
		System.out.println("ENTER EMPLOYEE ID VALUE SHOULD BE CHECK");
                 value4=in.nextInt();
		sql="select * from employee where empid="+value4+";";
		ResultSet rs=st.executeQuery(sql);
      		while(rs.next())
		{
			id=rs.getInt(1);
			name=rs.getString(2);
			address=rs.getString(3);
			designation=rs.getString(4);
			experience=rs.getInt(5);
			basicpay=rs.getInt(6);
			gradepay=rs.getInt(7);
			da=rs.getFloat(8);
			hra=rs.getFloat(9);
			pf=rs.getFloat(10);
			ts=rs.getFloat(11);
			total=rs.getFloat(12);
			System.out.println("THE ID:"+id);
			System.out.println("THE NAME:"+name);
			System.out.println("THE ADDRESS:"+address);
			System.out.println("THE DESIGNATION:"+designation);
			System.out.println("THE EXPERIENCE:"+experience);
			System.out.println("THE BASICPAY:"+basicpay);
                        System.out.println("THE GRADEPAY:"+gradepay);
                        System.out.println("THE DA:"+da);
                        System.out.println("THE HRA:"+hra);
                        System.out.println("THE TOTALSALARY:"+ts);
                        System.out.println("THE PF:"+pf);
                        System.out.println("THE SALARY:"+total);
			System.out.println("");
		}
		break;
			
  }if(choice==5)
	break;
}
  }
  public static int setsalary(String designation)
  {
    if(designation.equals("ap"))
      return 15000;
    else if(designation.equals("p"))
      return 20000;
    else if(designation.equals("clerk"))
      return 5000;
	return 0;
  }
	public static float setda(String designation)
  {
    if(designation.equals("ap"))
      return 25;
    else if(designation.equals("p"))
      return 50;
    else if(designation.equals("clerk"))
      return 10;
        return 0;
  }
public static float sethra(String designation)
  {
    if(designation.equals("ap"))
      return 1500;
    else if(designation.equals("p"))
      return 3000;
    else if(designation.equals("clerk"))
      return 500;
        return 0;
  }
public static int setpay(String designation)
  {
    if(designation.equals("ap"))
      return 5000;
    else if(designation.equals("p"))
      return 6000;
    else if(designation.equals("clerk"))
      return 500;
        return 0;
  }
public static String setname(int c)
  {
	String h="";
	if(c==1)
		return "empid";
	if(c==2)
	return "empname";
	if(c==3)
	return "address";
	if(c==4)
	return "designation";
	if(c==5)
	return "experience";
	return h;
}
}

