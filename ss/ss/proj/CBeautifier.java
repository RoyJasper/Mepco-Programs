import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.*;
import javax.swing.*;
public class CBeautifier implements ActionListener
{
    protected static JFrame f;
    static JLabel heading;
    static JLabel name;
    static JLabel pwd;
    static JButton Login;
    //static JButton SignUp;
    static JButton LogOut,Display;
    static JTextField Username;



    public  void access()
    {
        Login.addActionListener(this);
        //SignUp.addActionListener(this);
        LogOut.addActionListener(this);
       // Display.addActionListener(this);
    }
    public static void layout() throws SQLException, ClassNotFoundException
    {

        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        int width = (int) screenSize.getWidth();
        int height = (int) screenSize.getHeight();
        f=new JFrame();
        //f.setContentPane(new JLabel(new ImageIcon("D:\\"+ll+".jpg")));
        //f.setBackground(Color.BLACK);
        //getContentPane().setBackground(Color.BLACK);
        Container c = f.getContentPane();
        
   //     JLabel background=new JLabel(new ImageIcon("C:\\Users\\Roy Jasper\\Documents\\codeindend.png"));
    //	f.add(background);
    	f.setContentPane(new JLabel(new ImageIcon("C:\\Users\\Roy Jasper\\Documents\\e3b4fcb5d5a7674b463f09c11cfad5dd6b48af0f.jpg")));
        c.setBackground(Color.WHITE);
        heading=new JLabel(" BEAUTIFIER FOR C ");
        heading.setForeground(Color.WHITE);
        heading.setBounds(550,20,300,30);
        Font fo = new Font("Rockwell",Font.ITALIC,30);
        heading.setFont(fo);
        f.add(heading);
        name=new JLabel("SELECT FILE >");
        name.setBounds(250,150,300,35);
        name.setForeground(Color.WHITE);
        name.setFont(fo);
        f.add(name);

        f.setTitle("Beaufifier for C");

        Login=new JButton("OPEN FILE");
        Login.setBounds(600,150,100, 35);
        f.add(Login);
        
      //  Display=new JButton("DISPLAY FILE");
     //   Display.setBounds(800,150,150, 35);
     //   f.add(Display);
//
     //   JTextArea tarea = new JTextArea(200,100);
    //    tarea.setBounds(200,200 ,1000, 480);
    //    f.add(tarea);	
        LogOut=new JButton("Exit");
        LogOut.setBounds(1050,150,100, 35);
        f.add(LogOut);

        f.setSize(1366,768);
        f.setLayout(null);
        f.setVisible(true);


    }



    public void actionPerformed(ActionEvent ae)
    {
    	String fil = null;
        String str=ae.getActionCommand();
        if(str.equals("OPEN FILE"))
        {

            try
            {
              fil=readFile();
            }
            catch (Exception e)
            {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }

        }
        if(str.equals("Exit"))
        {
            f.setVisible(false);
            f.dispose();
            System.exit(0);
        }
        if(str.equals("DISPLAY FILE"))
        {
        	dfile(fil);
        }
   
            }
    public static void dfile(String fil)
    {
    	File file = new File(fil);
        try {
          BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
      //    tarea.read(input, "READING FILE :-)");
        //  tarea.
        } catch (Exception e) {
          e.printStackTrace();
        }	
    }
    public static String readFile()throws Exception
    {
        JFileChooser chooser = new JFileChooser();
        String fn = null;
        int filename = chooser.showOpenDialog(null);

        if (filename == JFileChooser.APPROVE_OPTION)
        {
            File f = chooser.getSelectedFile();

            String fname=f.getAbsolutePath();
            //System.out.println(fname);
            firstclean(fname);
            secondclean();
            thirdclean();
            fourthclean();
            fifthclean(fname);
            fn=fname;
        }
		return fn;
    }
    static void firstclean(String fil) throws IOException
    {
        int chara;
        char ch;
        @SuppressWarnings("resource")
        FileInputStream fin = new FileInputStream(fil);
        FileOutputStream fout = new FileOutputStream("temp.txt");

        while((chara=fin.read())!=-1)
        {
            ch = (char)chara;
            if(((Character.isAlphabetic(ch)||(ch>=32&&ch<=126))&&ch!='\n'))
            {
                if(ch=='\t')
                {

                }
                else
                {
                    fout.write(ch);
                    //System.out.print(ch);
                }
            }
        }
        fout.close();
        // TODO Auto-generated method stub

    }

    private static void secondclean() throws IOException
    {

        // TODO Auto-generated method stub
        int chara,chara1;
        char ch,ch1 ;
        String wrt;
        File file=new File("temp1st.txt");
        FileWriter fw = new FileWriter(file.getAbsoluteFile());
        BufferedWriter bout= new BufferedWriter(fw);
        FileInputStream fin = new FileInputStream("temp.txt");

        //FileOutputStream fout = new FileOutputStream("temp1st.txt");
        while((chara=fin.read())!=-1)
        {
            ch = (char)chara;
            if(ch=='>')
            {
                if(ch=='>')
                {
                	// System.out.print(ch+"\n");
                    wrt=ch+"\n";
                    bout.write(wrt);
                }
                else
                {
                	//  System.out.print(ch);
                    bout.write(ch);
                }
            }
            else if(ch==';')
            {
                if(ch==';')
                {
                	//  System.out.print(ch+"\n");
                    wrt=ch+"\n";
                    bout.write(wrt);
                }
                else
                {
                	//  System.out.print(ch);
                    bout.write(ch);
                }
            }
            else if(ch=='(')
            {
                chara1=fin.read();
                ch1 = (char)chara1;
                if((ch=='(')&&(ch1==')'))
                {
                	//  System.out.print(ch+""+ch1+"");
                    wrt=ch+""+ch1+"";
                    bout.write(wrt);
                }
                else if((ch=='(')&&(ch1!=')'))
                {
                	// System.out.print(ch+""+ch1);
                    bout.write(ch+""+ch1);
                    while((chara=fin.read())!=-1)
                    {
                        ch1=(char)chara;
                        if(ch1==')')
                            break;
                        else
                        {
                        	//   System.out.print(ch1);
                            bout.write(ch1);
                        }
                    }
                    // System.out.print(")");
                    bout.write(")");
                }
                else
                {
                	// System.out.print(ch+""+ch1);
                    wrt=ch+""+ch1;
                    bout.write(wrt);
                }
            }
            // NW ESDIT
            else if(ch=='{'||ch=='}')
            {
                wrt=""+ch+"";
                //  System.out.print(wrt);
                bout.write(wrt);
            }
            else
            {
            	//   System.out.print(ch);
                bout.write(ch);
            }
        }
        bout.close();
        fin.close();
    }



    private static void thirdclean() throws IOException
    {

        // TODO Auto-generated method stub
        int chara,chara1,ver=0,chk=0;
        char ch,ch1 ;
        String wrt;
        File file=new File("temp2nd.txt");
        FileWriter fw = new FileWriter(file.getAbsoluteFile());
        BufferedWriter bout= new BufferedWriter(fw);
        FileInputStream fin = new FileInputStream("temp1st.txt");
        //FileOutputStream fout = new FileOutputStream("temp2nd.txt");
        while((chara=fin.read())!=-1)
        {
            ch = (char)chara;
            if(ch=='{')
            {
                chk++;
                chara1=fin.read();
                ch1 = (char)chara1;
                if(ch1!='\n')
                {
                    if(ver==0)
                    {
                        wrt="\n"+ch+"\n"+ch1;
                        //    System.out.print(wrt);
                        bout.write(wrt);
                        ver=1;
                    }
                    else
                    {
                        wrt=""+ch+"\n"+ch1;
                        //   System.out.print(wrt);
                        bout.write(wrt);
                    }
                }

                /*	else if(!Character.isAlphabetic(ch1))
                	{
                		wrt="\n"+ch+"\n"+ch1;
                		System.out.print(wrt);// ?
                        bout.write(wrt);
                	}*/


            }
            else if(ch=='}')
            {
                chk--;
                chara1=fin.read();
                ch1 = (char)chara1;
                if(ch1!='\n')
                {
                    wrt=ch+"\n"+ch1;
                    //   System.out.print(wrt);// ?
                    bout.write(wrt);
                }

            }
            else
            {
            	// System.out.print(ch);
                bout.write(ch);
            }
            if(chk==0)
            {
                ver=0;
            }
        }
        bout.close();
        fin.close();
    }

    private static void fourthclean() throws IOException
    {
        // TODO Auto-generated method stub
        int chara,spc=0;
        char ch,ch1,ch2 ;
        String wrt;
        File file=new File("temp2ndb.txt");
        FileWriter fw = new FileWriter(file.getAbsoluteFile());
        BufferedWriter bout= new BufferedWriter(fw);
        FileInputStream fin = new FileInputStream("temp2nd.txt");
        while((chara=fin.read())!=-1)
        {
            ch = (char)chara;
            if(ch=='(')
            {
                spc++;
                //  System.out.print(ch);
                bout.write(ch);
                while((chara=fin.read())!=-1)
                {
                    ch1 = (char)chara;
                    if(spc!=0)
                    {
                        if(ch1=='(')
                            spc++;
                        if(ch1==')')
                            spc--;
                        if(spc!=0)
                        {
                        	//      System.out.print(ch1);
                            bout.write(ch1);
                        }
                    }
                    if(spc==0)
                    {
                        chara=fin.read();
                        ch2 = (char)chara;
                        if(ch2==';')
                        {
                            wrt=ch1+""+ch2;
                            //    System.out.print(wrt);
                            bout.write(wrt);
                        }
                        else
                        {
                            wrt=ch1+"\n"+ch2;
                            //   System.out.print(wrt);
                            bout.write(wrt);
                        }
                        break;
                    }
                }
            }
            else
            {
            	// System.out.print(ch);
                bout.write(ch);
            }
        }
        bout.close();
        fin.close();
    }


    private static void fifthclean(String fil) throws IOException
    {
        // TODO Auto-generated method stub
        int chara,spc=0,i,cond=0;
        char ch ;
        File f = new File(fil);
        f.delete();
        File file=new File(fil);
        FileWriter fw = new FileWriter(file.getAbsoluteFile());
        BufferedWriter bout= new BufferedWriter(fw);
        FileInputStream fin = new FileInputStream("temp2nd.txt");
        while((chara=fin.read())!=-1)
        {
            ch = (char)chara;
            if(ch=='{'&&cond==0)
            {
                spc++;
                for (i=0; i<spc; i++)
                {
                	//  System.out.print("  ");
                    bout.write(" ");
                }
                //    System.out.print(ch);
                bout.write(ch);
                cond=1;
            }
            else if(ch=='{')
            {
                spc++;
                //  System.out.print("\n"+"  ");
                bout.write("\n"+"  ");
                for (i=0; i<spc-1; i++)
                {
                	//     System.out.print("  ");
                    bout.write(" ");
                }
                //  System.out.print(ch);
                bout.write(ch);
            }
            else if(ch=='}')
            {
                spc--;
                for (i=0; i<spc-1; i++)
                {
                	//      System.out.print("  ");
                    bout.write(" ");
                }
                //  System.out.print(ch);
                bout.write(ch);

            }
            else
            {
                if(ch=='\n')
                {
                	//     System.out.print(ch);
                    bout.write(ch);
                    for (i=0; i<spc; i++)
                    {
                    	//       System.out.print("  ");
                        bout.write(" ");
                    }
                }
                else
                {
                	// System.out.print(ch);
                    bout.write(ch);
                }
            }
            if(spc==0)
            {
                cond=0;
            }
        }
        bout.close();
        fin.close();
        JOptionPane.showMessageDialog(null,"THE SELECTED CODE IS BEAUTIFIED");
    }
    public static void main(String[] args) throws ClassNotFoundException, SQLException
    {
        CBeautifier t =new CBeautifier();
        CBeautifier.layout();
        t.access();
    }

}
