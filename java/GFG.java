import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


class Pp extends JPanel implements ActionListener{
    JPanel pn = new JPanel();
    JTextField t1 = new JTextField("Input a");
    JTextField t2 = new JTextField("Input b");
    int n1,n2;
    static JTextField t3 = new JTextField();
    public void stuff(){
        
        pn.setSize(100,200);
        JButton bt = new JButton("add");
        JButton bt2 = new JButton("sub");
        n1 = Integer.parseInt(t1.getText());
        n2 = Integer.parseInt(t2.getText());
        bt.addActionListener(null);
        bt2.addActionListener(null);
        pn.add(t1);
        pn.add(t2);
        pn.add(bt);
        pn.add(bt2);
        pn.add(t3);
    }

    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == "add"){
            String str = ""+(n1+n2);
            t3.setText(str);
        }
        else if ( e.getSource() == "sub"){
            String str = ""+(n1-n2);
            t3.setText(str);
        }
    }
}

public class GFG{
    public static void main(String[] args) {
        Pp ob = new Pp();
        JFrame f = new JFrame();
        f.add(ob);
    }
}