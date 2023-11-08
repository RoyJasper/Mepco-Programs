	package image;
	import javax.swing.*;  

import java.awt.event.*;  
      
    public class Notepad implements ActionListener{  
    JFrame f;  
    JMenuBar mb;  
    JMenu file,edit,help;  
    JMenuItem cut,copy,paste,selectAll,h;  
    JTextArea ta;  
          
    Notepad(){  
    f=new JFrame();  
      
    cut=new JMenuItem("cut");  
    copy=new JMenuItem("copy");  
    paste=new JMenuItem("paste");  
    selectAll=new JMenuItem("selectAll");  
      h=new JMenuItem("HELP");
    cut.addActionListener(this);  
    copy.addActionListener(this);  
    paste.addActionListener(this);  
    selectAll.addActionListener(this);  
      
    mb=new JMenuBar();  
    mb.setBounds(5,5,100,40);  
      
    file=new JMenu("File");  
    edit=new JMenu("Edit");  
    help=new JMenu("Help");  
      
    edit.add(cut);edit.add(copy);edit.add(paste);edit.add(selectAll);  
      help.add(h);
      
    mb.add(file);mb.add(edit);mb.add(help);  
      
    ta=new JTextArea();  
    ta.setBounds(5,60,460,460);  
      
    f.add(mb);f.add(ta);  
     f.setName("NOTE PAD");
    f.setLayout(null);  
    f.setSize(500,500);  
    f.setVisible(true);  
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
    }  
      
    public static void main(String[] args) {  
        new Notepad();  
    }  
    }  