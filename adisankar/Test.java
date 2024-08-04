import java.util.Scanner;

public class Test{
    public static int add (int a, int b){
        int sum = a+b;
        return sum;
    }
    public static void main(String args[]){
        System.out.println("CUM");
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        System.out.println(a.charAt(2));
        
        sc.close();
        
    }
}