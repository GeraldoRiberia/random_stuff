import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;


class Screen extends JFrame implements ActionListener{
    JTextField t1,t2,t3; JLabel l1,l2,l3;
    JPanel p1; JButton b1,b2;

    Screen(){
        setSize(400,300);
        t1 = new JTextField(30);
        t2 = new JTextField(30);
        t3 = new JTextField(30);
        l1 = new JLabel("Enter value x");
        l2 = new JLabel("Enter value y");
        l3 = new JLabel("Result");
        b1 = new JButton("Add");
        b2 = new JButton("Subtract");
        b1.addActionListener(this);
        b2.addActionListener(this);
        p1 = new JPanel();
        p1.add(l1);
        p1.add(t1); 
        p1.add(l2);
        p1.add(t2);
        p1.add(l3);
        p1.add(t3);
        p1.add(b1); p1.add(b2);
        p1.setVisible(true);
        add(p1);
        setVisible(true);

    }

    public void actionPerformed(ActionEvent a){
        int s = 0;
        int x = Integer.parseInt(t1.getText());
        int y = Integer.parseInt(t2.getText());
        if(a.getSource() == b1){
            s = x+y;
        }
        else if(a.getSource() == b2){
            s = x-y;
        }
        t3.setText("Result : "+s);
    }
}

public class calculator {
    public static void main(String[] args) {
        Screen s1 = new Screen();
    }
    
}
