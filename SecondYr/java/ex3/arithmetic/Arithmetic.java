import java.io.*;
import java.util.*;
import pack.*;
public class Arithmetic {
	public static void main(String args[]){
		int a,b;
		Scanner obj=new Scanner(System.in);
		System.out.println("Enter 2 nos");
		a=obj.nextInt();
		b=obj.nextInt();
        Add a1=new Add();
        Sub s1=new Sub();
        Div d1=new Div();
        Mul m1=new Mul();
        System.out.println("Sub val is "+s1.subraction(a,b));
        System.out.println("Add val is "+a1.addition(a,b));
        System.out.println("Div val is "+d1.division(a,b));
        System.out.println("Mul val is "+m1.multiplication(a,b));
	}

}
