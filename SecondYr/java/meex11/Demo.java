
import java.util.*;
class Sample extends Thread
{
	int number;
	Sample(int n)
	{
		this.number=n;
	}
	public void run()
	{
		int i=0;
		System.out.println("EXTENDED THREAD CLASS");
		for(i=2;i<number-1;i++)
			if(number%i==0)
				break;
		if(number==i+1)
			System.out.println("PRIME NUMBER");
		else
			System.out.println("NOT PRIME NUMBER");
		}
	
	}
class Sample1 implements Runnable
{
	int num;
	public Sample1(int n)
	{
		this.num=n;
	}
	public void run()
	{
		int i=0;
		System.out.println("RUNNABLE INTERFACE");
		for(i=2;i<num-1;i++)
			if(num%i==0)
				break;
		if(num==i+1)
			System.out.println("PRIME NUMBER");
		else
			System.out.println("NOT PRIME NUMBER");
		}
}
public class Demo
{
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		System.out.println("ENTER A NUMBER");
		int n=in.nextInt();
		Sample s=new Sample(n);
		Sample1 s1=new Sample1(n);
		s.start();
		Thread t=new Thread(s1);
		try {
			t.join();
		} catch (InterruptedException e) {e.printStackTrace();}
		t.start();
	}
}
