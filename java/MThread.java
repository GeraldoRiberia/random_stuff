import java.util.*;
class Thread1 extends Thread
{
    Thread1(){
        start();
    }

    public void run()
    {
        for(int i=0;i<=10;i=i+2)
        {
            System.out.println("even" +i);
            try
            {
                sleep(2000);
            }
            catch(InterruptedException e)
            {
                System.out.println("Clock error");
            }
        }
    }
}
class Thread2 extends Thread
{
    Thread2(){
        start();
    }
    public void run()
    {
        for(int i=1;i<=10;i=i+2)
        {
            System.out.println("odd" +i);
            try
            {
                sleep(2000);
            }
            catch(InterruptedException e)
            {
                System.out.println("Clock error");
            }
        }
    }
}
class Mthread
{
public static void main(String[] args)
{
    new Thread1();
    new Thread2();
}
}