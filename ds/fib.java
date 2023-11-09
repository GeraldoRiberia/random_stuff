import java.util.*;
class Fib{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter n");
        int n=sc.nextInt();
        int first =0;
        int second =1;
        System.out.print(first+" ");
        System.out.print(second+" ");
        int third;
        for(int i =2;i<n;i++){
            third = first+second;
            System.out.print(third+" ");
            first = second;
            second = third;
        }
    }
}