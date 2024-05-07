import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
class Cal extends JFrame implements ActionListener{
    JTextField tx,ty,tr;
    JLabel lx,ly,lr;
    JButton badd,bsub;
    JPanel p1;
    public static void main(String[] args) {
        new Cal();
    }
    Cal(){
        setSize(400,300);
        tx = new JTextField(10);
        ty = new JTextField(10);
        tr = new JTextField(30);
        lx = new JLabel("Enter x");
        ly = new JLabel("Enter y");
        lr = new JLabel("Result");
        p1 = new JPanel();
        badd = new JButton("Add");
        bsub = new JButton("Subtract");
        badd.addActionListener(this);
        bsub.addActionListener(this);
        p1.add(lx);p1.add(tx);
        p1.add(ly);p1.add(ty);
        p1.add(lr);p1.add(tr);
        p1.add(badd);
        p1.add(bsub);
        p1.setVisible(true);
        add(p1);
        setVisible(true);
    }
    public void actionPerformed(ActionEvent e){
        int s;
        int x = Integer.parseInt(tx.getText());
        int y = Integer.parseInt(ty.getText());
        if(e.getSource() == badd){
            s = x+y;
            tr.setText("Sum is "+s);
        }
        if(e.getSource() == bsub){
            s = x-y;
            tr.setText("Difference is "+s);
        }
    }
}