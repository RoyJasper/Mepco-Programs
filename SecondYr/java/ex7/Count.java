import java.io.*;

public class Count
{

  public static void main(String[] args) throws IOException
  {
    FileInputStream obj1=new FileInputStream(args[0]);
    char n;
    int ch,c=0;
    String  s;
    while((ch=obj1.read())!=-1)
    {
      n=(char)ch;
      s=""+n;
      if(s.equals(args[1]))
      {
        c=c+1;
      }

    }
    System.out.println("Occurance are...  "+c);

  }

}

