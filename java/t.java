import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
class p1 extends JFrame implements ActionListener
{
    JTextField tx,ty,tr;
    JLabel lx,ly,lr;
    JButton badd,bsub;
    Panel p1;
    public static void main(String args[])
    {
        new p1();
    }
    p1(){
        setSize(400,400);
        tx=new JTextField(30);
        ty=new JTextField(30);
        tr=new JTextField(30);
        lx=new JLabel("enter x");
        ly=new JLabel("enter x");
        badd=new JButton("ADD");
        bsub=new JButton("SUBTRACT");
        lr=new JLabel("result");
        p1=new Panel();
        p1.add(lx);p1.add(tx);
        p1.add(ly);p1.add(ty);
        p1.add(badd);p1.add(bsub);
        p1.add(tr);p1.add(lr);
        badd.addActionListener(this);
        bsub.addActionListener(this);
        p1.setVisible(true);
        add(p1);
        setVisible(true);
    }
    public void actionPerformed(ActionEvent e)
    {
        int s;
        int x=Integer.parseInt(tx.getText());
        int y=Integer.parseInt(ty.getText());
        if(e.getSource()==badd)
        {
            s=x+y;
            tr.setText("sum is"+s);
        }
        if(e.getSource()==bsub)
        {
            s=x-y;
            tr.setText("difference is"+s);
        }
    }
}