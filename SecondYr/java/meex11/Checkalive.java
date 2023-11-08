

public class Checkalive implements Runnable
{
Thread t;
Checkalive()
{
	t=new Thread(this,"DATA THREAD");
	t.start();
}
public void run()
{
	for(int i=0;i<10;i++)
	{
		randomWait();
		System.out.println(""+i);
}}
public boolean check()
{
	return t.isAlive();
}
void randomWait()
{
    try {
       t.sleep((long)(800*Math.random()));
    } catch (InterruptedException x) {
       System.out.println("Interrupted!");
    }
}

public static void main(String args[])
{
	boolean ch;
	Checkalive a=new Checkalive();
	Checkalive b=new Checkalive();
	for(int i=0;i<5;i++)
	{
	a.randomWait();
	if(a.check())
		System.out.println("I st THREAD WAS RUNNING");
	else
		System.out.println("I st THREAD WAS DEAD");
	b.randomWait();
	if(b.check())
		System.out.println("II st THREAD WAS RUNNING");
	else
		System.out.println("II st THREAD WAS DEAD");
	}
}
}