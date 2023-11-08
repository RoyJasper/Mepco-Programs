import java.io.*;
abstract class Beauty
{

    public static void main(String args[]) throws IOException
    {
        int chara,spc=0,i,cond=0;
        char ch,ch1,ch2 ;
        String wrt;
        File file=new File("temp2ndb.txt");
        FileWriter fw = new FileWriter(file.getAbsoluteFile());
        BufferedWriter bout= new BufferedWriter(fw);
        @SuppressWarnings("resource")
        FileInputStream fin = new FileInputStream("temp2nd.txt");
         while((chara=fin.read())!=-1)
        {
            ch = (char)chara;
            if(ch=='{'&&cond==0)
            {
                spc++;
                for (i=0; i<spc; i++)
                {
                    System.out.print(" _ ");
                }
                System.out.print(ch);
                cond=1;
            }
            else if(ch=='{')
            {
                spc++;
                for (i=0; i<spc-1; i++)
                {
                    System.out.print(" _ ");
                }
                System.out.print(ch);

            }
            else if(ch=='}')
            {
                spc--;
                for (i=0; i<spc-1; i++)
                {
                    System.out.print(" _ ");
                }
                System.out.print(ch);

            }
            else
            {
                if(ch=='\n')
                {
                    System.out.print(ch);
                    for (i=0; i<spc; i++)
                    {
                        System.out.print(" _ ");
                    }
                }
                else
                {
                    System.out.print(ch);
                }
            }
            if(spc==0)
            {
                cond=0;
            }
        }
            
		}
}
