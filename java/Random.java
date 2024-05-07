import java.math.*;

class Thread1 extends Thread{

    Thread1(){
        start();
    }

    public void run(){
        int n = (int)(Math.random()*10);
        if(n%2 == 0){
            new Thread2(n);
        }
        else{
            new Thread3(n);
        }
    }
}

class Thread2 extends Thread{
    int n;
    Thread2(int n){
        this.n = n;
        start();
    }

    public void run(){
        System.out.print("Even numbers from 1 to "+n+" : ");
        for(int i= 1; i<=n; i++){
            if(i%2 == 0){
                System.out.print(i+",");
            }
        }
        System.out.println();
    }
}

class Thread3 extends Thread{
    int n;
    Thread3(int n){
        this.n = n;
        start();
    }

    public void run(){
        System.err.println("Prime numbers from 1 to "+n+" : ");
        for(int i= 1; i<=n; i++){
            int fcount =0;
            for(int j = 1; j<=i;j++){
                if(i%j == 0){
                    fcount++;
                }
            }
            if(fcount == 2){
                System.out.print(i+",");
            }
        }
    }
}

class Random{
    public static void main(String[] args) {
        new Thread1();
    }
}