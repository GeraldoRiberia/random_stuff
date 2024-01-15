
class Thread1 extends Thread{
    Thread1(){
        run();
    }
    public void run(){
        for(int i =1; i<=10; i++){
            if(i % 2 == 0){
                try{sleep(1000);}
                catch(Exception e){}
            }
            else{
                
            }
            try{sleep(1000);}
                catch(Exception e){}
        }
    }
}

class Thread2 extends Thread{
    Thread2(){
        
    }
}
public class ttt {
    
}
