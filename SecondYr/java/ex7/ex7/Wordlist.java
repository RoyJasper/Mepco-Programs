import java.io.*;;

public class Wordlist {

public static void main(String[] args) throws IOException {
	FileInputStream obj1=new FileInputStream(args[0]);
	FileOutputStream obj=new FileOutputStream(args[1]);
	FileOutputStream obj2=new FileOutputStream(args[2]);
	int []a=new int[50];
	String []s1=new String[50];
	int i=0,ch=0,j,k;
	char n;
	byte l;
	while(ch!=-1)
	{	s1[i]="";
		while((ch=obj1.read())!=-1)
		{
		n=(char)ch;
		if((n==' ')||(n=='\n'))
			break;
		s1[i]=""+s1[i]+n;
		}
		i++;
	}
	int m = i;
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(s1[i].equals(s1[j]))
			{
				a[i]=a[i]+1;
				for(k=j+1;k<m;k++)
				{
					s1[k-1]=""+s1[k];
				}
				j=j-1;
				m=m-1;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		System.out.println(s1[i]+a[i]);
	}
	String s="";
	int b;
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(s1[i].compareTo(s1[j])>0)
			{
				s= s1[i];
				s1[i]=s1[j];
				s1[j]=s;
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	i=0;
	byte p;
	while(i!=m)
	{
		k=s1[i].length();
		j=0;
		while(j!=k)
		{
			ch=(char)s1[i].charAt(j);
			j++;
			l=(byte)ch;
			obj.write(l);
		}
		i++;
		
	}
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(a[i]<a[j])
			{
				s= s1[i];
				s1[i]=s1[j];
				s1[j]=s;
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	i=0;
	while(i!=m)
	{
		k=s1[i].length();
		j=0;
		while(j!=k)
		{
			ch=(char)s1[i].charAt(j);
			j++;
			l=(byte)ch;
			obj2.write(l);
		}
		i++;
		
	}
}
}
