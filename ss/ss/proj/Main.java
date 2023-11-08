import java.io.*;
import java.util.Scanner;
import javax.swing.*;


@SuppressWarnings("serial")
public class Main extends JFrame
{
    public Main()
    {
    }

	public static void main(String[] args) throws Exception
	{
		
		readFile();
	}

	public static void readFile()throws Exception
	{
         JFileChooser chooser = new JFileChooser();

    int filename = chooser.showOpenDialog(null);

	if (filename == JFileChooser.APPROVE_OPTION){
		File f = chooser.getSelectedFile();
		
		String fname=f.getAbsolutePath();
	    System.out.println(fname);
	   } 

	}
}
