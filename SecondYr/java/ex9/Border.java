package image;
import java.awt.*;  
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;  
  
public class Border implements ActionListener {  
JFrame f;
int i=0;
JButton bu[]=new JButton[17];
String s[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q"};
Border(){  
    f=new JFrame();  
    for(i=0;i<17;i++)
    bu[i]=new JButton(s[i]);
       
    /*JButton b2=new JButton("B");;  
    JButton b3=new JButton("C");;  
    JButton b4=new JButton("D");;  
    JButton b5=new JButton("E");;  
      
    f.add(b1,BorderLayout.NORTH);  
    f.add(b2,BorderLayout.SOUTH);  
    f.add(b3,BorderLayout.EAST);  
    f.add(b4,BorderLayout.WEST);  
    f.add(b5,BorderLayout.CENTER);  
      */
    bu[0].setBounds(0,0,200,50);
    bu[1].setBounds(0,50,67,50);
    bu[2].setBounds(67,50,67,50);
    bu[3].setBounds(134,50,66,50);
    bu[4].setBounds(0,100,200,50);
    for(i=5;i<11;i++)
    {
    	if(i<8)
    	bu[i].setBounds(i-i,((i-5))*50+150,150,50);
    	else
    	bu[i].setBounds(i-i+150,((i-8)*50)+150,150,50);
    }
    for(i=11;i<17;i++)
    bu[i].setBounds(200,(i-11)*30,100,30);
    bu[15].setBounds(200,120,100,30);
    for(i=0;i<17;i++)
    {
    	f.add(bu[i]);
    	bu[i].addActionListener(this);
    }
    f.setSize(300,340); 
    f.setVisible(true);  
}  
public void actionPerformed(ActionEvent ae)
{
	for(i=0;i<17;i++)
	{
	if(ae.getSource()==bu[i])
		JOptionPane.showMessageDialog(null,"PRESSED BUTTON IS "+s[i]);
	}
}
public static void main(String[] args) {  
    new Border();  
}  
}  