package pack2;
import pack1.A;
import java.io.*;
public class C {
	public static void print2(){
		A object=new A();
		System.out.println((object.a)+" Public");
		System.out.println(" Private Not accesble");
		System.out.println(" Protected Not accesble");
		System.out.println(" Default Not accesble");
	}
}
