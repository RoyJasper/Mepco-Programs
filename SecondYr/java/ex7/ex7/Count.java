import java.io.*;

public class Count {
	public static void main(String[] args) throws IOException {
		FileInputStream obj1 = new FileInputStream(args[0]);
		char n;
		int ch,word=1,line=1,character=0;
		String  s;
		while((ch=obj1.read())!=-1)
		{	n=(char)ch;
			if(n==(' '))
			{
				word=word+1;
			}
			if(n==('\t'))
			{
				line=line+1;
				word=word+1;
			}
			character=character+1;
		}
		System.out.println("Characters are  "+character);
		System.out.println("Words are "+word);
		System.out.println("Lines are "+line);
	}
}
