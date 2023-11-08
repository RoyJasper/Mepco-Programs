
import java.util.Scanner;
public class Timer extends Thread
{
	int n;
	public Timer(int nt)
	{
		this.n=nt;
	}
	public void run()
	{
		for(int i=n;i>0;i--)
		{
			try {
		           sleep((long)(2000));
		        } catch (InterruptedException x) {
		           System.out.println("Interrupted!");
		        }
			System.out.println(""+i);
		}
	}
	
	public static void main(String args[])
	{
		int nt=0;
		Scanner in=new Scanner(System.in);
		System.out.println("ENTER NUMBER TO SNOOZE");
		nt=in.nextInt();
		Timer t=new Timer(nt);
		Thread tt=new Thread(t);
		tt.start();
		in.close();
	}
	
}
