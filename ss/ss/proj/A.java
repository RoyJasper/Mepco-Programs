 import java.io.*;
3:    import java.awt.*;
4:    import java.awt.event.*;
5:    import java.applet.*;
6:    import javax.swing.*;
7:    import javax.swing.border.*;
8:
9:    public class TestApplet extends JApplet
      implements ActionListener {
10:   private JPanel pane = null;
11:     private JScrollPane scrolling = null;
12:     private JTextPane fileBox = null;
13:     private JTextField tfFilename = null;
14:     private JButton butLoad = null;
15:     private final String LOAD = "load";
16:
17:   public void init() {
18:   try {
19:       jbInit();
20:     } catch(Exception e) {
21:       e.printStackTrace();
22:     }
23:   }
24:
25:   // method which will read data from file, and return it in
      // String
25:   public String readFile(String fn) {
26:     String thisLine, ret = "";
27:     try {
28:       FileInputStream fin =  new FileInputStream(fn);
29:       BufferedReader myInput = new BufferedReader
                         (new InputStreamReader(fin));
30:       while ((thisLine = myInput.readLine()) != null) {  
31:         ret += thisLine + "\n";
32:       }
33:     } catch (Exception e) {
34:       ret = "Cannot load, exception!";
35:     }
36:     return ret;
37:   }
39:
40:   private void jbInit() throws Exception {
41:     pane = new JPanel();
42:     pane.setBounds(new Rectangle(0, 0, 500, 325));
43:     pane.setLayout(null);
44:     pane.setBorder(BorderFactory.createEtchedBorder(
                       EtchedBorder.LOWERED));
45:     pane.setBackground(new Color(221, 194, 219));
46:
47:     fileBox = new JTextPane();
48:     fileBox.setText("");
49:     fileBox.setEditable(false);
50:     scrolling = new JScrollPane(fileBox);
51:     scrolling.setBounds(new Rectangle(16, 65, 295, 225));
52:
53:     tfFilename = new JTextField();
54:     tfFilename.setText("");
55:     tfFilename.setBounds(new Rectangle(16, 23, 206, 29));
56:
57:     butLoad = new JButton();
58:     butLoad.setBounds(new Rectangle(231, 23, 80, 30));
59:     butLoad.setText("Load");
60:     butLoad.setActionCommand(LOAD);
61:     butLoad.addActionListener(this);
62:
63:     pane.add(scrolling);
64:     pane.add(tfFilename);
65:     pane.add(butLoad);
66:
67:     setContentPane(pane);
68:   }
69:
70:   public void actionPerformed(ActionEvent e) {
71:     if (e.getActionCommand().equals(LOAD)) {
72:         fileBox.setText(readFile(tfFilename.getText()));
73:     }
74:   }
75: }