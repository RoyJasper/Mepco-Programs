import java.io.*;
import java.util.*;
class Person < T >
{
}
class Student extends Person
{
String name;
T m1,m2,m3,m4,tot,avg,grade;
}
abstract public void getdetails()
{
}
abstract public void display()
{
}
}
class UG extends Student
{
String name;
T m1,m2,m3,m4,tot,avg,grade;
public void getdetails()
{
System.out.println("Enter the Name");

}
abstract public void display()
{
}
}



