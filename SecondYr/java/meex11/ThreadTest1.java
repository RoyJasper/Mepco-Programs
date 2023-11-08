
class ThreadTest1
{
    public static void main(String args[])
    {
        MyThread thread1 = new MyThread("thread1: ");
        MyThread thread2 = new MyThread("thread2: ");
        MyThread thread3 = new MyThread("thread3: ");
        thread1.start();
        thread2.start();
        thread3.start();
        boolean thread1IsAlive = true;
        boolean thread2IsAlive = true;
        boolean thread3IsAlive = true;
        do {
           if (thread1IsAlive && !thread1.isAlive()) {
               thread1IsAlive = false;
System.out.println("Thread 1 is dead.");
           }
           if (thread2IsAlive && !thread2.isAlive()) {
               thread2IsAlive = false;
               System.out.println("Thread 2 is dead.");
           }
           if (thread3IsAlive && !thread3.isAlive()) {
               thread3IsAlive = false;
               System.out.println("Thread 3 is dead.");
           }
        } while(thread1IsAlive || thread2IsAlive || thread3IsAlive );
    }
}
class MyThread extends Thread
{
static String message[] ={ "Java", "J2EE", "Spring", "Stnuts"};
    public MyThread(String id)
    {
        super(id);
    }
    public void run()
    {
        String name = getName();
        for (int i=0;i<message.length;++i) {
           randomWait();
           System.out.println(name + message[i]);
        }
    }
    void randomWait()
    {
        try {
           sleep((long)(8000*Math.random()));
        } catch (InterruptedException x) {
           System.out.println("Interrupted!");
        }
    }
}
