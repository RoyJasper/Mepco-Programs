import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class MainClass {
    public static void main(String args[]) throws InterruptedException {
        EmailMessageQueueClass messageQueue = new EmailMessageQueueClass();
        new Thread(new Consumer(messageQueue)).start();
        for (int i = 0; i < 1000; ++i) {
            new Thread(new Producer("Email Message " + i, messageQueue))
                    .start();
        }
    }
}

class Producer implements Runnable {
    EmailMessageQueueClass messageQueue;
    String emailMessageContent;

    public Producer(String message, EmailMessageQueueClass messageQueue) {
        emailMessageContent = message;
        this.messageQueue = messageQueue;
    }

    public void run() {
        try {
            messageQueue.adds(emailMessageContent);
        } catch (InterruptedException e1) {
            e1.printStackTrace();
        }
    }
}

class Consumer implements Runnable {
    EmailMessageQueueClass messageQueue;

    public Consumer(EmailMessageQueueClass messageQueue) {
        this.messageQueue = messageQueue;
    }

    public void run() {
        try {
            messageQueue.retrieve();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class EmailMessageQueueClass {

    Queue<String> q = new LinkedList<String>();
    private int queueMaxSize = 10;

    synchronized void retrieve() throws InterruptedException {
        while (true) {
            while (q.isEmpty()) {
                wait();
            }
            q.remove();
            System.out.print("Mail Queue::::::[");
            Iterator<String> it = q.iterator();
            while (it.hasNext())
                System.out.print(it.next() + ",");
            System.out.print("]");
            System.out.println();
            notifyAll();
        }
    }

    synchronized void adds(String emailMessage) throws InterruptedException {
        while (q.size() == queueMaxSize) {
            wait();
        }
        q.add(emailMessage);
        System.out.print("Mail Queue::::::[");
        Iterator<String> it = q.iterator();
        while (it.hasNext())
            System.out.print(it.next() + ",");
        System.out.print("]");
        System.out.println();
        notify();
    }
}

