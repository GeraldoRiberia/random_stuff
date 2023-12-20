import java.io.BufferedReader;
import java.io.FileReader;
import java.util.*;
public class FileH {
    public static void main(String[] args) {
        int n, s=0;
        String str= null;
        BufferedReader br = null;
        try{
            br = new BufferedReader(new FileReader("a.txt"));
        }
        catch(Exception e ){}
        try{
            str =br.readLine();
        }
        catch(Exception e ){}
        while(str != null){
            n = Integer.parseInt(str);
            s += n;
            try{
                str = br.readLine();
            }
            catch(Exception e){}
        }
        System.out.println("Sum = "+s);
    }
}
