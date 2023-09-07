import java.util.*;
public class calc {
    public static double add(double n1, double n2){
        return n1+n2;
    }
    public static double  sub(double n1, double n2){
        return n1-n2;
    }
    public static double mult(double n1, double n2){
        return n1*n2;
    }
    public static double div(double n1, double n2){
        return n1/n2;
    }
    public static double mod(double n1,double n2){
        return n1%n2;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        double n1,n2,res=0;char op;
        while(true){
        try{
        n1 = sc.nextDouble();
        op = sc.next().charAt(0);
        n2 = sc.nextDouble();
        switch(op){
            case '+': res += add(n1,n2);
                    System.out.println(res);
                    break;
            case '-': res += sub(n1,n2);
                    System.out.println(res);
                    break;
            case '*': res+=mult(n1, n2);
                    System.out.println(res);
                    break;
            case '/': res+= div(n1, n2);
                    System.out.println(res);
                    break;
            case '%': res+= mod(n1, n2);
                    System.out.println(res);
                    break;
            case 'r': res = 0; break;
            default : System.out.println("Invalid Choice");
        }
        }
        catch(Exception e){
            System.out.println("Extited!");
            break;
        }
        
        
        
    }
    sc.close();
}
}