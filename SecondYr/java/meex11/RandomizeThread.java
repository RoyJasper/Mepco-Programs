
import java.util.Random;
class RandomizeThread implements Runnable
{
Random r = new Random();
int number;
public void run() {
number = r.nextInt(10) + 1;
}
int getNumber(){
return number;
}
public static void main (String args[]) throws InterruptedException {
RandomizeThread rt1 = new RandomizeThread();
RandomizeThread rt2 = new RandomizeThread();
RandomizeThread rt3 = new RandomizeThread();
RandomizeThread rt4 = new RandomizeThread();
RandomizeThread rt5 = new RandomizeThread();

Thread t1=new Thread(rt1);
Thread t2=new Thread(rt2);
Thread t3=new Thread(rt3);
Thread t4=new Thread(rt4);
Thread t5=new Thread(rt5);

t1.start();
t2.start();
t3.start();
t4.start();
t5.start();

t1.join();
t2.join();
t3.join();
t4.join();
t5.join();

System.out.println("rt1: " + rt1.getNumber());
System.out.println("rt2: " + rt2.getNumber());
System.out.println("rt3: " + rt3.getNumber());
System.out.println("rt4: " + rt4.getNumber());
System.out.println("rt5: " + rt5.getNumber());

int total = 0;
total = total + rt1.getNumber();
total = total + rt2.getNumber();
total = total + rt3.getNumber();
total = total + rt4.getNumber();
total = total + rt5.getNumber();

System.out.println("Total: " + total);
}
}

