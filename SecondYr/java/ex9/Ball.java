package image;
import java.awt.*;
import javax.swing.*;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Graphics;
public class Ball extends Canvas implements ActionListener
{
  JFrame fr;
  JButton left,right;
  Graphics g;
  JLabel lab,move;
  int i=0,j=0;
  public void init()
  {
		fr=new JFrame("LET'S START GAME");
		Container c = fr.getContentPane();
		c.setBackground(Color.orange);
		Font font = new Font("Segoe Print", Font.BOLD,20);
		left=new JButton("LEFT");
		right=new JButton("RIGHT");
		lab=new JLabel("______________________________________________________________");
		move =new JLabel("______________");
		lab.setFont(font);
		lab.setBounds(0,350,500,30);
		move.setBounds(300,320,400,20);
		move.setFont(font);
		fr.add(lab);
		fr.add(move);
		left.setBounds(75,400,100,30);
		fr.add(left);
		right.setBounds(225,400,100,30);
		fr.add(right);
		left.addActionListener(this);
		right.addActionListener(this);
		//g.drawLine(0, 400,300,300);
		fr.setSize(500,500);//400 width and 500 height  
		fr.setLayout(null);//using no layout managers  
		fr.setVisible(true); 	
		//g.setColor(Color.black);
		 // g.drawLine(500, 400,800,900);
		 // g.drawString("HELLO",40,40);
		
  }
  int k=300;
@Override
public void actionPerformed(ActionEvent ae)
{   
	String str=ae.getActionCommand();
	if(str.equals("LEFT") && k!=0)
	{  
		k=k-30;
	   //fr.setVisible(false);
	   move.setBounds(k,320,400,20);
	   fr.add(move);
	   fr.setVisible(true);
		
	    }
	
	if(str.equals("RIGHT") && k<=360)
	{
		k=k+30;
		   //fr.setVisible(false);
		   move.setBounds(k,320,400,20);
		   fr.add(move);
		   fr.setVisible(true);
	    }
	}
	

public static void main(String args[])
{
	
	Ball b=new Ball();
	b.init();
	
	
}
}
