	
	import javax.swing.*;

import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.event.*;  
      
    public class Order implements ActionListener{  
    JFrame f;  
    JMenuBar mb;  
    JMenu file,edit,help;  
    JMenuItem cut,copy,paste,selectAll,h,newq,save;  
    JTextArea ta;  
    JLabel order,meal,options;
    JButton cancel,place;
    JTextField ordert;
    JRadioButton in,out;
    ButtonGroup eat;
    JComboBox mealt;
    String food[]={"Hamburger","Noodles","Springroll","Rice","Pizza","Barbeque","Kabap","Smiles","Burger"};
          
    Order(){  
    f=new JFrame();  
    Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
	int width = (int) screenSize.getWidth();
	int height = (int) screenSize.getHeight();
	Container c=f.getContentPane();
	c.setBackground(Color.white);
    mealt=new JComboBox();
    mealt.setBounds(610,50,100,30);
    for(int i=0;i<9;i++)
    mealt.addItem(food[i]);
    f.add(mealt);
    cut=new JMenuItem("cut");  
    copy=new JMenuItem("copy");  
    paste=new JMenuItem("paste");  
    selectAll=new JMenuItem("selectAll");  
    h=new JMenuItem("HELP");
    cut.addActionListener(this);  
    copy.addActionListener(this);  
    paste.addActionListener(this);  
    selectAll.addActionListener(this);  
    order=new JLabel("ORDER TYPE:");
    order.setBounds(100,50,100,30);
    f.add(order);
    ordert=new JTextField(20);
    ordert.setBounds(210,50,100,30);
    f.add(ordert);
    cancel=new JButton("Cancel");
    cancel.setBounds(500,500,150,30);
    f.add(cancel);
    place=new JButton("Place Order");
    place.setBounds(700,500,150,30);
    f.add(place);
    
    meal=new JLabel("MEAL TYPE:");
    meal.setBounds(500,50,100,30);
    f.add(meal);
    options=new JLabel("OPTIONS");
    options.setBounds(400,150,100,30);
    f.add(options);
    in=new JRadioButton("eat in");
    in.setBounds(200,250,100,30);
    f.add(in);
    out=new JRadioButton("Take out");
    out.setBounds(200,300,100,30);
    f.add(out);
    eat=new ButtonGroup();
    eat.add(in);
    eat.add(out);
    mb=new JMenuBar();  
    mb.setBounds(5,5,100,40);  
      
    file=new JMenu("File");  
    edit=new JMenu("Edit");  
    help=new JMenu("Help");  
    newq =new JMenuItem("new");
    save=new JMenuItem("save");
    file.add(newq);
    file.add(save);
    edit.add(cut);edit.add(copy);edit.add(paste);edit.add(selectAll);  
    help.add(h);
    newq.addActionListener(this);
    save.addActionListener(this);
    mb.add(file);
    mb.add(edit);
    mb.add(help);  
      
    ta=new JTextArea(); 
    ta.setText("Write any Special \nRequest here");
   // ta.setBounds(5,60,460,460);  
    JScrollPane jsp = new JScrollPane(ta,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
	jsp.setBounds(500,200,300,200);
    f.add(mb);
    f.add(jsp);  
    f.setName("NOTE PAD");
    f.setLayout(null);  
    f.setSize(1000,700);  
    f.setVisible(true); 
    place.addActionListener(this);
    cancel.addActionListener(this);
    f.setSize(width,height);
    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
    }  
      
    public void actionPerformed(ActionEvent e) {  
    if(e.getSource()==cut)  
    ta.cut();  
    if(e.getSource()==paste)  
    ta.paste();  
    if(e.getSource()==copy)  
    ta.copy();  
    if(e.getSource()==selectAll)  
    ta.selectAll();
    if(e.getSource()==h)
    {
    f.setVisible(false);
    ta.setText("VERSION V.1");
    f.add(ta);
    f.setVisible(true);  
    }
    if(e.getSource()==newq)
    {
    	Order o=new Order();
    }
    if(e.getSource()==place)
    {
    	JOptionPane.showMessageDialog(null, "ORDER ACCEPTED");
    	f.setVisible(false);
    }
    if(e.getSource()==cancel)
    {
    	JOptionPane.showMessageDialog(null, "ORDER CANCELLED");
    	f.setVisible(false);
    }
    
    }  
      
    public static void main(String[] args) {  
        new Order();  
    }  
    }  