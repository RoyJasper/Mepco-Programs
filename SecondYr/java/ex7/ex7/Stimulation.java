import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Stimulation {

	public static void main(String[] args) throws IOException {
		System.out.println("1.COPY 2.CAT");
		Scanner in=new Scanner(System.in);
		int choice=in.nextInt();
		int ch;
		byte n;
		char na;
		String s;
		switch(choice)
		{
		case 1:
			FileInputStream obj1=new FileInputStream(args[0]);
			FileOutputStream obj=new FileOutputStream(args[1]);
			while((ch=obj1.read())!=-1)
			{	n=(byte)ch;
				obj.write(n);	
			}
			break;
		case 2:
			if(args.length == 1)
			{
				FileInputStream obj2=new FileInputStream(args[0]);
				while((ch=obj2.read())!=-1)
				{	na=(char)ch;
					System.out.print(na);
				}
			}
			else
			{	System.out.println(args[1]);
				if(args[1].equals(">"))
				{
					FileInputStream obj3=new FileInputStream(args[0]);
					FileOutputStream obj4=new FileOutputStream(args[2]);
					while((ch=obj3.read())!=-1)
					{	n=(byte)ch;
						obj4.write(n);	
					}
				}
				if(args[1].equals(">>"))
				{
					FileInputStream obj3=new FileInputStream(args[0]);
					FileWriter obj4 = new FileWriter(args[2],true);
					BufferedWriter bw = new BufferedWriter(obj4);
					while((ch=obj3.read())!=-1)
					{	na=(char)ch;
						s=""+na;	
						bw.write(na);
					}
				}
			}
				
		}
		

	}

}
