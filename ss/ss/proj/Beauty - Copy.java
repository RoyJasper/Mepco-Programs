import java.util.*;
import java.io.*;
abstract class Beauty
{

    static void clean1(String fil) throws IOException {
    	int i,chara;
		char ch;
		System.out.println(" in clean");
		FileInputStream fin = new FileInputStream(fil);
		 FileOutputStream fout = new FileOutputStream("temp.txt");
		 while((chara=fin.read())!=-1)
		 {
			 ch = (char)chara;
			if(Character.isAlphabetic(ch)||((ch>=33)&&(ch<=64)||(ch>=91)&&(ch<=96)||(ch==126)||(ch==124)||(ch==127)||(ch==' ')||(ch=='{')||(ch=='}')))
			{
				fout.write(ch);
			}
		 }
		// TODO Auto-generated method stub
		
	}
    @SuppressWarnings("resource")
    public static void main(String args[]) throws IOException
    {
        int i,chara,spc=0,brac=0;
        char c,ch ;
        String fil;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the program name with extension : ");
        //fil=in.next();
        fil="b.c";
		clean1(fil);
        //Stack<Character> st = new Stack<Character>();
        FileInputStream fin = new FileInputStream("temp.txt");

       // FileOutputStream fout = new FileOutputStream("temp.txt");
        while((chara=fin.read())!=-1)
        {
            ch = (char)chara;
            if((ch=='{')&&(spc==0))
            {
                System.out.print(ch);
                //fout.write(ch);
                spc++;
				brac++;
                System.out.println("");
                //fout.write('\n');
				for(i=0;i<spc;i++)
				{
					System.out.print("  |  ");
				}
				chara=fin.read();
				

            }
            else if(ch=='}')
            {
                System.out.print(ch);
                //fout.write(ch);
                spc--;
            }
            else if(Character.isAlphabetic(ch)||((ch>=33)&&(ch<=58)||(ch>=60)&&(ch<=64)||(ch>=91)&&(ch<=96)||(ch==126)||(ch==124)||(ch==127)||(ch=='\n')||(ch==' ')))
            {

                //fout.write(ch);
                System.out.print(ch); 
            }
			else if((ch=='{')&&(spc!=0))
            {
				//chara=fin.read();
				//System.out.println();
				for(i=0;i<spc-1;i++)
				{
					System.out.print("  -_-  ");
				}
				System.out.println(ch);
				for(i=0;i<spc;i++)
				{
					System.out.print("  _|_  ");
				}
                
                //fout.write(ch);
                spc++;
               // System.out.println("");
                //fout.write('\n');

            }
        }
System.out.println(brac);
System.out.println(spc);

    }

}

--------------------------------------------------------------------
4 clean:::


if(ch=='{')
            {
                spc++;
	            for(i=0; i<=spc; i++)
                {
                    System.out.print(" ");
                }
                System.out.print(ch);
                /* if(spc==0)
                {
                	System.out.print(ch+"\n");
                	for(i=0;i<=spc;i++)
                	{
                		chara1=fin.read();
                		ch1 = (char)chara1;

                	}
                } */
				chara1=fin.read();
				ch1 = (char)chara1;
				System.out.print(ch1);
				for(i=0; i<=spc; i++)
                {
                    System.out.print(" ");
                }
                while((chara1=fin.read())!=125)
                {
					//uncondi();
                    ch1 = (char)chara1;
                    if(ch1==';')
                    {
                        System.out.print(ch1);
                        chara2=fin.read();
                        ch2 = (char)chara2;
                        System.out.print(ch2);
                        for(i=0; i<=spc; i++)
                        {
                            System.out.print(" ");
                        }
                    }
                    else
                    {
                        System.out.print(ch1);
                    }
                }
                System.out.print('}');

            }
            else
            {
                System.out.print(ch);
            }
