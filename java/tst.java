import java.io.*;
public class tst {
    public static void main(String[] args) {
        char ch='a';
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try{ch = (char)br.read();}
        catch(Exception e ){}
        System.out.println(ch);
    }
}
