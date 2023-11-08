package image;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.JLabel;
@SuppressWarnings("serial")
public class Background extends Applet implements ActionListener
{
	Color c;
	List ls;
	Label lab;
	Button b,b1;
	int red=0,green=0,blue=0;
	int color[][]={ {0,0,0},{0,0,255},{0,255,0},{255,0,0},{0,255,255},{255,0,255},{255,255,0},{255,255,255}};
	
	public void init()
	{
		ls=new List(8,true);
		lab=new Label("HERE COMES OUTPUT!!...");
		b=new Button("SET BACKGROUND");
		b1=new Button("SET FOREGROUND");
		ls.add("Black",0);
		ls.add("Blue",1);
		ls.add("Green",2);
		ls.add("Red",3);
		ls.add("Cyan",4);
		ls.add("Magneta",5);
		ls.add("Yellow",6);
		ls.add("White",7);
		lab.setBounds(400,400,300,30);
		add(ls);
		add(b);
		add(b1);
		add(lab);
		ls.addActionListener(this);
		b.addActionListener(this);
		b1.addActionListener(this);
	}public void paint(Graphics g){}
	public void actionPerformed(ActionEvent ae)
	{
		String st=ae.getActionCommand();
		int[] clr;
		int i;
		if(st.equals("SET BACKGROUND"))
		{
			red=green=blue=0;
			clr=ls.getSelectedIndexes();
			for(i=0; i<clr.length;i++)
			{

				red=red+color[clr[i]][0];
				green=green+color[clr[i]][1];
				blue=blue+color[clr[i]][2];
				
				
				}
			red=red/clr.length;
			green=green/clr.length;
			blue=blue/clr.length;
			c=new Color(red,green,blue);
			setBackground(c);
			}
		if(st.equals("SET FOREGROUND"))
		{
			red=green=blue=0;
			clr=ls.getSelectedIndexes();
			for(i=0; i<clr.length;i++)
			{

				red=red+color[clr[i]][0];
				green=green+color[clr[i]][1];
				blue=blue+color[clr[i]][2];
				
				
				}
			red=red/clr.length;
			green=green/clr.length;
			blue=blue/clr.length;
			c=new Color(red,green,blue);
			lab.setForeground(c);

		}
		}
	}
	

