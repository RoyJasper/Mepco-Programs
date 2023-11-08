import java.util.Scanner;

public class People<T,T1>
{
	public T name;
	public T rollno;
	public T department;
	public T1 mark1;
	public T1 mark2;
	public T1 mark3;
	public T1 mark4;
	public T1 mark5;
	public T1 mark6;
	public People(T tname,T troll,T depart,T1 m1,T1 m2,T1 m3,T1 m4,T1 m5,T1 m6)
	{
		this.name=tname;
		this.rollno=troll;
		this.department=depart;
		mark1=m1;
		mark2=m2;
		mark3=m3;
		mark4=m4;
		mark5=m5;
		mark6=m6;
	}
	public People(T tname,T troll)
	{
		this.name=tname;
		this.rollno=troll;
	}
	@SuppressWarnings("unchecked")
	public T1 getTotal()
	{	
		if(mark1 instanceof Integer)
		return (T1) (Integer) ((Integer)mark1+(Integer)mark2+(Integer)mark3+(Integer)mark4+(Integer)mark5+(Integer)mark6);
		if(mark1 instanceof Double)
		return (T1) (Double) ((Double)mark1+(Double)mark2+(Double)mark3+(Double)mark4+(Double)mark5+(Double)mark6);
			
		return null;
	}
	public T1 getSalary()
	{	
		//if(mark2 instanceof Double)
		 return (T1) (Double) ((Double)mark1+((Double)(mark2)* (Double)mark1)+((Double)mark3*(Double)mark1)-(Double)mark4);
		 //return null;
	}
	public T getname(){return name;}
	public T getroll(){return rollno;}
	public T getdepart(){return department;}
	public void setname(T tname){name=tname;}
	public void setrollno(T troll){rollno=troll;}
	
	public static void main(String args[])
	{
		String nam,roll,departm;
		int[] mar=new int[6];
		Double[] mart=new Double[6];
		do
		{
		System.out.println("\nENTER \n1.UG STUDENT\t<String,Integer>\n2.PG STUDENT\t<String,Float>\n3.EMPLOYEE\t<String,Double>");
		Scanner in=new Scanner(System.in);
		int choice =in.nextInt();
		in.nextLine();
		switch(choice)
		{
		case 1:
				System.out.println("ENTER UG STUDENT NAME:");
				nam=in.nextLine();
				System.out.println("ENTER UG STUDENTROLL No:");
				roll=in.nextLine();
				System.out.println("ENTER UG DEPARTMENT:");
				departm=in.nextLine();
				System.out.println("ENTER MARKS");
				for(int i=0;i<6;i++)
				{
					mar[i]=in.nextInt();
				}
				People<String,Integer> ug=new People(nam,roll,departm,mar[0],mar[1],mar[2],mar[3],mar[4],mar[5]);
				System.out.println("NAME:		"+ug.getname());
				System.out.println("ROLLNO:		"+ug.getroll());
				System.out.println("DEPARTMENT: "+ug.getdepart());
				System.out.println("TOTAL MARK:	"+ug.getTotal());
				break;
		case 2:
			System.out.println("ENTER PG STUDENT NAME:");
			nam=in.nextLine();
			System.out.println("ENTER PG STUDENT ROLL No:");
			roll=in.nextLine();
			System.out.println("ENTER PG DEPARTMENT:");
			departm=in.nextLine();
			System.out.println("ENTER MARKS");
			for(int i=0;i<6;i++)
			{
				mart[i]=in.nextDouble();
			}
			People<String,Double> pg=new People(nam,roll,departm,mart[0],mart[1],mart[2],mart[3],mart[4],mart[5]);
			System.out.println("NAME:  		"+pg.getname());
			System.out.println("ROLLNO:  	"+pg.getroll());
			System.out.println("DEPARTMENT: "+pg.getdepart());
			System.out.println("TOTAL MARK:	"+pg.getTotal());
			break;
		case 3:
			System.out.println("ENTER STAFF NAME:");
			nam=in.nextLine();
			System.out.println("ENTER STAFF ID:");
			roll=in.nextLine();
			System.out.println("ENTER STAFF WORKING DEPARTMENT:");
			departm=in.nextLine();
			System.out.println("ENTER BASIC");
			mart[0]=in.nextDouble();
			System.out.println("ENTER HRA");
			mart[1]=in.nextDouble();
			System.out.println("ENTER DA");
			mart[2]=in.nextDouble();
			System.out.println("ENTER PF");
			mart[3]=in.nextDouble();
			mart[4]=0.0;
			mart[5]=0.0;			
			People<String,Double> emp=new People(nam,roll,departm,mart[0],mart[1],mart[2],mart[3],mart[4],mart[5]);
			System.out.println("NAME: 		"+emp.getname());
			System.out.println("ROLLNO:  	"+emp.getroll());
			System.out.println("DEPARTMENT: "+emp.getdepart());
			System.out.println("SALARY:  "+emp.getSalary());
			break;
		}
	}
	while(true);
	}

}
