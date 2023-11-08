

import java.util.Scanner;
import java.util.function.Consumer;

public class Problem
{
 int size=0,capacity=5;
 String []product=new String[5];
 Scanner in=new Scanner(System.in);
 class Customer extends Thread
 {
	 synchronized
	 public void run()
	 {

	for(int i=0;i<10;i++)
	{
		 if(size!=capacity)
		 {
			 System.out.println("ENTER NEW PRODUCT");
			 product[size]=in.nextLine();
			 size++;
		 }
		 else
			 System.out.println("SHOP WAS FULL");
	      }
	 }	 
 }
 class Producer extends Thread
 {
	 
	 synchronized
	 public void run()
	 {
		 for(int i=0;i<10;i++)
		 {
		 if(size>0)
		 {
			 size--;
			 System.out.println("CONSUMED PRODUCT"+product[size]);
			 
		 }
		 else
		 {
			try {
		           sleep((long)(15000));
		        } catch (InterruptedException x) {
		           System.out.println("Interrupted!");
		        }
			
			 System.out.println("SHOP WAS EMPTY");
		 	}
		 }
	 }
 }
 public static void main(String args[])
 {
	 Problem p=new Problem();
	 
	 Problem.Producer pro=p.new Producer();
	 Problem.Customer con=p.new Customer();
	 con.start();
	 pro.start();
		
	 try {
		 con.join();
		 pro.join();
	 	} catch (InterruptedException e) {}
	 }
 }

